#include <windows.h>
#include <stdio.h>
#include "packet_logger.h"
#include "hooking.h"
#include "memscan.h"


LPCSTR SEND_PATTERN = "\x53\x56\x8B\xF2\x8B\xD8\xEB\x04";
LPCSTR RECV_PATTERN = "\x55\x8B\xEC\x83\xC4\xF4\x53\x56\x57\x33\xC9\x89\x4D\xF4\x89\x55\xFC\x8B\xD8\x8B\x45\xFC";
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

