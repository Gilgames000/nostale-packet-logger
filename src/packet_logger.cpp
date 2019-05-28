#include "stdafx.h"
#include <stdio.h>
#include "packet_logger.h"
#include "hooking.h"


void customSend()
{
	char *packet;

	_asm
	{
		MOV packet, EDX
	}

	printf("[SEND]: %s\n", packet);
}

void customRecv()
{
	char *packet;

	_asm
	{
		MOV packet, EDX
	}

	printf("[RECV]: %s", packet);
}

void startLogger()
{
	FILE* dummy;

	AllocConsole();
	freopen_s(&dummy, "CONIN$", "r", stdin);
	freopen_s(&dummy, "CONOUT$", "w", stdout);
	freopen_s(&dummy, "CONOUT$", "w", stderr);
}

void stopLogger()
{
	FreeConsole();
}

void hookSend()
{
	bool outcome;

	printf("[INFO]: Hooking send function... ");
	outcome = hookFunction((LPVOID)SEND_ADDRESS, customSend);
	printf("%s\n", outcome ? "SUCCESS" : "FAILURE");
}

void unhookSend()
{
	bool outcome;

	printf("[INFO]: Unhooking send function... ");
	outcome = unhookFunction((LPVOID)SEND_ADDRESS);
	printf("%s\n", outcome ? "SUCCESS" : "FAILURE");
}

void hookRecv()
{
	bool outcome;

	printf("[INFO]: Hooking recv function... ");
	outcome = hookFunction((LPVOID)RECV_ADDRESS, customRecv);
	printf("%s\n", outcome ? "SUCCESS" : "FAILURE");
}

void unhookRecv()
{
	bool outcome;

	printf("[INFO]: Unhooking recv function... ");
	outcome = unhookFunction((LPVOID)RECV_ADDRESS);
	printf("%s\n", outcome ? "SUCCESS" : "FAILURE");
}

