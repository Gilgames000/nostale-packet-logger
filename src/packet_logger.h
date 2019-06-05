#pragma once
#include "safequeue.h"

BOOL StartLogger(SafeQueue* sqSendPackets, SafeQueue* sqRecvPackets);
BOOL StopLogger();
void SendPacket(LPCSTR szPacket);
void ReceivePacket(LPCSTR szPacket);