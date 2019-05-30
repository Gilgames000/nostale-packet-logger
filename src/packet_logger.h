#pragma once

BOOL FindAddresses();
VOID StartLogger();
VOID StopLogger();
BOOL HookSend();
BOOL HookRecv();
BOOL UnhookSend();
BOOL UnhookRecv();