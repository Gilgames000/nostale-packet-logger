#include "stdafx.h"
#include "hooking.h"


const DWORD HOOK_SIZE = 6;
const DWORD TRAMPOLINE_SIZE = HOOK_SIZE + 14;

LPVOID createTrampoline(LPVOID originalFunction, LPVOID customFunction, BYTE* bytesBackup) {
	LPVOID trampoline;
	DWORD pushregsAddy;
	DWORD customcallAddy;
	DWORD popregsAddy;
	DWORD bytesbackupAddy;
	DWORD backjumpAddy;
	DWORD dummy;

	// Allocate the memory for the trampoline function
	trampoline = VirtualAlloc(NULL, TRAMPOLINE_SIZE, MEM_RESERVE | MEM_COMMIT, PAGE_READWRITE);
	if (!trampoline) return nullptr;

	// Compute the addresses beforehand (just for clarity)
	pushregsAddy = (DWORD)trampoline;
	customcallAddy = pushregsAddy + 2;
	popregsAddy = customcallAddy + 5;
	bytesbackupAddy = popregsAddy + 2;
	backjumpAddy = bytesbackupAddy + HOOK_SIZE;

	// Write the trampoline function to memory
	// 
	// PUSHAD                             ; backup the registers
	// PUSHFD                             ; backup the flags
	// CALL customFunction                ; call the customFunction
	// POPFD                              ; restore the flags
	// POPAD                              ; restore the registers
	// ...                                ; execute bytesBackup
	// JMP originalFunction + HOOK_SIZE   ; jump back to the original function
	//
	*(BYTE*)pushregsAddy = _ASM_OP_PUSHAD;
	*(BYTE*)(pushregsAddy + 1) = _ASM_OP_PUSHFD;

	*(BYTE*)customcallAddy = _ASM_OP_CALL;
	*(DWORD*)(customcallAddy + 1) = ((DWORD)customFunction - customcallAddy - 5);

	*(BYTE*)popregsAddy = _ASM_OP_POPFD;
	*(BYTE*)(popregsAddy + 1) = _ASM_OP_POPAD;

	if (!memcpy((LPVOID)bytesbackupAddy, bytesBackup, HOOK_SIZE))
	{
		VirtualFree(trampoline, 0, MEM_RELEASE);
		return false;
	}

	*(BYTE*)backjumpAddy = _ASM_OP_JMP;
	*(DWORD*)(backjumpAddy + 1) = (((DWORD)originalFunction + HOOK_SIZE) - backjumpAddy - 5);

	// Change the access protection to make the trampoline function executable
	if (!VirtualProtect(trampoline, TRAMPOLINE_SIZE, PAGE_EXECUTE_READ, &dummy)
		|| !FlushInstructionCache(GetCurrentProcess(), trampoline, TRAMPOLINE_SIZE))
	{
		VirtualFree(trampoline, 0, MEM_RELEASE);
		return nullptr;
	}

	return trampoline;
}

bool hookFunction(LPVOID originalFunction, LPVOID customFunction)
{
	DWORD oldProtect;
	LPVOID trampoline;
	BYTE bytesBackup[HOOK_SIZE];

	// Change access protection of the original function's bytes where the jump will be written
	if (!VirtualProtect(originalFunction, HOOK_SIZE, PAGE_EXECUTE_READWRITE, &oldProtect))
	{
		return false;
	}

	// Backup the instructions that will be overwritten
	if (!memcpy(bytesBackup, originalFunction, HOOK_SIZE)) return false;

	// Create a trampoline function that will call the customFunction, execute bytesBackup, and jump back
	trampoline = createTrampoline(originalFunction, customFunction, bytesBackup);
	if (trampoline == nullptr) return false;

	// Write a jump to the trampoline function
	*(BYTE*)originalFunction = _ASM_OP_JMP;
	*(DWORD*)((DWORD)originalFunction + 1) = ((DWORD)trampoline - (DWORD)originalFunction - 5);
	*(BYTE*)((DWORD)originalFunction + 5) = _ASM_OP_NOP;

	// Restore the old access protection of the original function's bytes
	VirtualProtect(originalFunction, HOOK_SIZE, oldProtect, &oldProtect);

	return true;
}

bool unhookFunction(LPVOID originalFunction)
{
	DWORD oldProtect;
	LPVOID bytesBackup;
	LPVOID trampoline;
	DWORD offset;

	// Retrieve trampoline and bytesBackup addresses
	if (!memcpy(&offset, (LPVOID)((DWORD)originalFunction + 1), 5)) return false;
	trampoline = (LPVOID)((DWORD)originalFunction + offset + 5);
	bytesBackup = (LPVOID)((DWORD)trampoline + 9);

	// Change access protection of the original function's bytes where the backup will be restored
	if (!VirtualProtect(originalFunction, HOOK_SIZE, PAGE_EXECUTE_READWRITE, &oldProtect)) return false;

	// Restore the backup of the instructions previously overwritten
	if (!memcpy(originalFunction, bytesBackup, HOOK_SIZE)) return false;

	// Restore the old access protection of the original function's bytes
	if (!VirtualProtect(originalFunction, HOOK_SIZE, oldProtect, &oldProtect)) return false;

	// Free the memory previously allocated for the trampoline
	return VirtualFree(trampoline, 0, MEM_RELEASE);
}