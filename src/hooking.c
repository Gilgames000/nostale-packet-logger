#include <windows.h>
#include "hooking.h"


#define HOOK_SIZE         6
#define TRAMPOLINE_SIZE   (HOOK_SIZE + 14)

#define _ASM_OP_PUSHAD    0x60
#define _ASM_OP_PUSHFD    0x9C
#define _ASM_OP_POPAD     0x61
#define _ASM_OP_POPFD     0x9D
#define _ASM_OP_CALL      0xE8
#define _ASM_OP_JMP       0xE9
#define _ASM_OP_NOP       0x90
#define _ASM_OP_RET       0xC3

LPVOID CreateTrampoline(LPVOID lpfnTarget, LPVOID lpfnHook, LPBYTE lpBytesBackup) {
    LPVOID lpTrampoline;
    DWORD_PTR pdwPushRegsAddy;
    DWORD_PTR pdwHookCallAddy;
    DWORD_PTR pdwPopRegsAddy;
    DWORD_PTR pdwBytesBackupAddy;
    DWORD_PTR pdwBackjumpAddy;
    DWORD fdwDummy;

    // Allocate the memory for the trampoline function
    lpTrampoline = VirtualAlloc(NULL, TRAMPOLINE_SIZE, MEM_RESERVE | MEM_COMMIT, PAGE_READWRITE);
    if (!lpTrampoline) return NULL;

    // Compute the addresses beforehand (just for clarity)
    pdwPushRegsAddy = (DWORD_PTR)lpTrampoline;
    pdwHookCallAddy = pdwPushRegsAddy + 2;
    pdwPopRegsAddy = pdwHookCallAddy + 5;
    pdwBytesBackupAddy = pdwPopRegsAddy + 2;
    pdwBackjumpAddy = pdwBytesBackupAddy + HOOK_SIZE;

    // Write the trampoline to memory
    // 
    // PUSHAD                             ; backup the registers
    // PUSHFD                             ; backup the flags
    // CALL lpfnHook                      ; call the hook function
    // POPFD                              ; restore the flags
    // POPAD                              ; restore the registers
    // ...                                ; execute backed up instructions
    // JMP lpfnTarget + HOOK_SIZE         ; jump back to the target function
    //
    *(BYTE*)pdwPushRegsAddy = _ASM_OP_PUSHAD;
    *(BYTE*)(pdwPushRegsAddy + 1) = _ASM_OP_PUSHFD;

    *(BYTE*)pdwHookCallAddy = _ASM_OP_CALL;
    *(DWORD*)(pdwHookCallAddy + 1) = ((DWORD_PTR)lpfnHook - pdwHookCallAddy - 5);

    *(BYTE*)pdwPopRegsAddy = _ASM_OP_POPFD;
    *(BYTE*)(pdwPopRegsAddy + 1) = _ASM_OP_POPAD;

    if (!memcpy((LPVOID)pdwBytesBackupAddy, lpBytesBackup, HOOK_SIZE))
    {
        VirtualFree(lpTrampoline, 0, MEM_RELEASE);
        return FALSE;
    }

    *(BYTE*)pdwBackjumpAddy = _ASM_OP_JMP;
    *(DWORD*)(pdwBackjumpAddy + 1) = ((DWORD_PTR)lpfnTarget + HOOK_SIZE) - pdwBackjumpAddy - 5;

    // Change the access protection to make the trampoline function executable
    if (!VirtualProtect(lpTrampoline, TRAMPOLINE_SIZE, PAGE_EXECUTE_READ, &fdwDummy)
        || !FlushInstructionCache(GetCurrentProcess(), lpTrampoline, TRAMPOLINE_SIZE))
    {
        VirtualFree(lpTrampoline, 0, MEM_RELEASE);
        return NULL;
    }

    return lpTrampoline;
}

BOOL HookFunction(LPVOID lpTarget, LPVOID lpHook)
{
    DWORD fdwOldProtect;
    LPVOID lpTrampoline;
    BYTE aBytesBackup[HOOK_SIZE];

    // Change access protection of the target function's bytes where the jump will be written
    if (!VirtualProtect(lpTarget, HOOK_SIZE, PAGE_EXECUTE_READWRITE, &fdwOldProtect))
    {
        return FALSE;
    }

    // Backup the instructions that will be overwritten
    if (!memcpy(aBytesBackup, lpTarget, HOOK_SIZE)) return FALSE;

    // Create a trampoline that will call the hook function, execute the overwritten instructions, and jump back
    lpTrampoline = CreateTrampoline(lpTarget, lpHook, aBytesBackup);
    if (!lpTrampoline) return FALSE;

    // Write a jump to the trampoline function
    *(BYTE*)lpTarget = _ASM_OP_JMP;
    *(DWORD*)((DWORD_PTR)lpTarget + 1) = (DWORD_PTR)lpTrampoline - (DWORD_PTR)lpTarget - 5;
    *(BYTE*)((DWORD_PTR)lpTarget + 5) = _ASM_OP_NOP;

    // Restore the old access protection of the target function's bytes
    VirtualProtect(lpTarget, HOOK_SIZE, fdwOldProtect, &fdwOldProtect);

    return TRUE;
}

BOOL UnhookFunction(LPVOID lpTarget)
{
    DWORD fdwOldProtect;
    LPBYTE lpBytesBackup;
    LPVOID lpTrampoline;
    DWORD_PTR pOffset;

    // Retrieve trampoline and bytesBackup addresses
    if (!memcpy(&pOffset, (LPVOID)((DWORD_PTR)lpTarget + 1), 5)) return FALSE;
    lpTrampoline = (LPVOID)((DWORD_PTR)lpTarget + pOffset + 5);
    lpBytesBackup = (LPBYTE)lpTrampoline + 9;

    // Change access protection of the target function's bytes where the backup will be restored
    if (!VirtualProtect(lpTarget, HOOK_SIZE, PAGE_EXECUTE_READWRITE, &fdwOldProtect)) return FALSE;

    // Restore the backup of the instructions previously overwritten
    if (!memcpy(lpTarget, lpBytesBackup, HOOK_SIZE)) return FALSE;

    // Restore the old access protection of the target function's bytes
    if (!VirtualProtect(lpTarget, HOOK_SIZE, fdwOldProtect, &fdwOldProtect)) return FALSE;

    // Free the memory previously allocated for the trampoline
    return VirtualFree(lpTrampoline, 0, MEM_RELEASE);
}