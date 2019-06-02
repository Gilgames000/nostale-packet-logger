#include <windows.h>
#include <stdio.h>
#include "packet_logger.h"
#include "hooking.h"
#include "memscan.h"


const BYTE SEND_PATTERN[] = { 0x53, 0x56, 0x8B, 0xF2, 0x8B, 0xD8, 0xEB, 0x04 };
const BYTE RECV_PATTERN[] = { 0x55, 0x8B, 0xEC, 0x83, 0xC4, 0xF4, 0x53, 0x56, 0x57, 0x33, 0xC9, 0x89, 0x4D, 0xF4, 0x89, 0x55, 0xFC, 0x8B, 0xD8, 0x8B, 0x45, 0xFC };
LPCSTR SEND_MASK = "xxxxxxxx";
LPCSTR RECV_MASK = "xxxxxxxxxxxxxxxxxxxxxx";

LPVOID lpvSendAddy;
LPVOID lpvRecvAddy;

void CustomSend()
{
    LPSTR szPacket;

    _asm
    {
        MOV szPacket, EDX
    }

    printf("[SEND]: %s\n", szPacket);
}

void CustomRecv()
{
    LPSTR szPacket;

    _asm
    {
        MOV szPacket, EDX
    }

    printf("[RECV]: %s", szPacket);
}

void StartLogger()
{
    FILE* pDummy;

    AllocConsole();
    freopen_s(&pDummy, "CONIN$", "r", stdin);
    freopen_s(&pDummy, "CONOUT$", "w", stdout);
    freopen_s(&pDummy, "CONOUT$", "w", stderr);
}

void StopLogger()
{
    FreeConsole();
}

BOOL FindAddresses()
{
    printf("[INFO]: Scanning process memory to find send address... ");
    lpvSendAddy = FindPattern(SEND_PATTERN, SEND_MASK);
    printf("%s\n", lpvSendAddy ? "SUCCESS" : "FAILURE");

    printf("[INFO]: Scanning process memory to find recv address... ");
    lpvRecvAddy = FindPattern(RECV_PATTERN, RECV_MASK);
    printf("%s\n", lpvRecvAddy ? "SUCCESS" : "FAILURE");

    return lpvSendAddy && lpvRecvAddy;
}

BOOL HookSend()
{
    BOOL bOutcome;

    printf("[INFO]: Hooking send function... ");
    bOutcome = HookFunction(lpvSendAddy, CustomSend);
    printf("%s\n", bOutcome ? "SUCCESS" : "FAILURE");

    return bOutcome;
}

BOOL HookRecv()
{
    BOOL bOutcome;

    printf("[INFO]: Hooking recv function... ");
    bOutcome = HookFunction(lpvRecvAddy, CustomRecv);
    printf("%s\n", bOutcome ? "SUCCESS" : "FAILURE");

    return bOutcome;
}

BOOL UnhookSend()
{
    BOOL bOutcome;

    printf("[INFO]: Unhooking send function... ");
    bOutcome = UnhookFunction(lpvSendAddy);
    printf("%s\n", bOutcome ? "SUCCESS" : "FAILURE");

    return bOutcome;
}

BOOL UnhookRecv()
{
    BOOL bOutcome;

    printf("[INFO]: Unhooking recv function... ");
    bOutcome = UnhookFunction(lpvRecvAddy);
    printf("%s\n", bOutcome ? "SUCCESS" : "FAILURE");

    return bOutcome;
}

