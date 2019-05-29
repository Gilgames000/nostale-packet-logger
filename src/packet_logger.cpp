#include "stdafx.h"
#include <stdio.h>
#include "packet_logger.h"
#include "hooking.h"
#include "memscan.h"


LPVOID sendAddy;
LPVOID recvAddy;

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

bool findAddresses()
{
	sendAddy = findPattern((BYTE*)SEND_PATTERN, (char*)SEND_MASK, SEND_LEN);
	recvAddy = findPattern((BYTE*)RECV_PATTERN, (char*)RECV_MASK, RECV_LEN);

	return sendAddy && recvAddy;
}

bool hookSend()
{
	bool outcome;

	printf("[INFO]: Hooking send function... ");
	outcome = hookFunction(sendAddy, customSend);
	printf("%s\n", outcome ? "SUCCESS" : "FAILURE");

	return outcome;
}

bool hookRecv()
{
	bool outcome;

	printf("[INFO]: Hooking recv function... ");
	outcome = hookFunction(recvAddy, customRecv);
	printf("%s\n", outcome ? "SUCCESS" : "FAILURE");

	return outcome;
}

bool unhookSend()
{
	bool outcome;

	printf("[INFO]: Unhooking send function... ");
	outcome = unhookFunction(sendAddy);
	printf("%s\n", outcome ? "SUCCESS" : "FAILURE");

	return outcome;
}

bool unhookRecv()
{
	bool outcome;

	printf("[INFO]: Unhooking recv function... ");
	outcome = unhookFunction(recvAddy);
	printf("%s\n", outcome ? "SUCCESS" : "FAILURE");

	return outcome;
}

