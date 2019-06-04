#pragma once
#include "safequeue.h"

BOOL StartLogger(SafeQueue* sqSendPackets, SafeQueue* sqRecvPackets);
BOOL StopLogger();