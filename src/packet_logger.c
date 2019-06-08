#include <windows.h>
#include "packet_logger.h"
#include "hooking.h"
#include "memscan.h"
#include "nostale_string.h"

const BYTE SEND_PATTERN[] = { 0x53, 0x56, 0x8B, 0xF2, 0x8B, 0xD8, 0xEB, 0x04 };
const BYTE RECV_PATTERN[] = { 0x55, 0x8B, 0xEC, 0x83, 0xC4, 0xF4, 0x53, 0x56, 0x57, 0x33, 0xC9, 0x89, 0x4D, 0xF4, 0x89, 0x55, 0xFC, 0x8B, 0xD8, 0x8B, 0x45, 0xFC };
const BYTE PACKET_THIS_PATTERN[] = { 0xA1, 0x00, 0x00, 0x00, 0x00, 0x8B, 0x00, 0xE8, 0x00, 0x00, 0x00, 0x00, 0xA1, 0x00, 0x00, 0x00, 0x00, 0x8B, 0x00, 0x33, 0xD2, 0x89, 0x10 };

LPCSTR SEND_MASK = "xxxxxxxx";
LPCSTR RECV_MASK = "xxxxxxxxxxxxxxxxxxxxxx";
LPCSTR PACKET_THIS_MASK = "x????xxx????x????xxxxxx";

LPVOID lpvSendAddy;
LPVOID lpvRecvAddy;
LPVOID lpvPacketThis;

SafeQueue* qSend;
SafeQueue* qRecv;

BOOL FindAddresses();
BOOL HookSend();
BOOL HookRecv();
BOOL UnhookSend();
BOOL UnhookRecv();


#pragma managed(push, off)
void CustomSend()
{
    LPSTR szPacket;

    _asm
    {
        MOV szPacket, EDX
    }

    qSend->push(szPacket);
}

void CustomRecv()
{
    LPSTR szPacket;

    _asm
    {
        MOV szPacket, EDX
    }

    qRecv->push(szPacket);
}

void SendPacket(LPCSTR szPacket)
{
    NostaleStringA str(szPacket);
    char* packet = str.get();

    _asm
    {
        MOV EAX, DWORD PTR DS : [lpvPacketThis]
        MOV EAX, DWORD PTR DS : [EAX]
        MOV EAX, DWORD PTR DS : [EAX]
        MOV EDX, packet
        CALL lpvSendAddy
    }
}

void ReceivePacket(LPCSTR szPacket)
{
    NostaleStringA str(szPacket);
    char* packet = str.get();

    _asm
    {
        MOV EAX, DWORD PTR DS : [lpvPacketThis]
        MOV EAX, DWORD PTR DS : [EAX]
        MOV EAX, DWORD PTR DS : [EAX]
        MOV EAX, [EAX + 0x34]
        MOV EDX, packet
        CALL lpvRecvAddy
    }
}
#pragma managed(pop)

BOOL StartLogger(SafeQueue* qSendPackets, SafeQueue* qRecvPackets)
{
    qSend = qSendPackets;
    qRecv = qRecvPackets;

    return FindAddresses() && HookSend() && HookRecv();
}

BOOL StopLogger()
{
    return UnhookSend() && UnhookRecv();
}

BOOL FindAddresses()
{
    lpvSendAddy = FindPattern(SEND_PATTERN, SEND_MASK);
    lpvRecvAddy = FindPattern(RECV_PATTERN, RECV_MASK);

    DWORD pThisPacket = (DWORD_PTR)FindPattern(PACKET_THIS_PATTERN, PACKET_THIS_MASK) + 0x1;
    lpvPacketThis = (LPVOID)*(DWORD*)pThisPacket;

    return lpvSendAddy && lpvRecvAddy && lpvPacketThis;
}

BOOL HookSend()
{
    return HookFunction(lpvSendAddy, CustomSend);
}

BOOL HookRecv()
{
    return HookFunction(lpvRecvAddy, CustomRecv);
}

BOOL UnhookSend()
{
    return UnhookFunction(lpvSendAddy);
}

BOOL UnhookRecv()
{
    return UnhookFunction(lpvRecvAddy);
}

