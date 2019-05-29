#include "stdafx.h"
#include <stdio.h>
#include "packet_logger.h"


BOOL APIENTRY DllMain(HMODULE hModule, DWORD  fdwReason, LPVOID lpvReserved);
DWORD WINAPI UnloadDll(LPVOID lpParameter);


DWORD WINAPI UnloadDll(LPVOID hLibModule) {

	printf("[INFO]: Press VK_END to unload the dll\n");
	while (1)
	{
		if (GetAsyncKeyState(VK_END) & 1)
		{
			printf("[INFO]: VK_END pressed; unloading the dll...\n");
			FreeLibraryAndExitThread((HMODULE)hLibModule, 0);
		}
	}
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD  fdwReason, LPVOID lpvReserved)
{
	switch (fdwReason)
	{
	case DLL_PROCESS_ATTACH:
		startLogger();
		if (findAddresses() && hookSend() && hookRecv())
			CreateThread(nullptr, 0, UnloadDll, hModule, 0, nullptr);
		break;
	case DLL_PROCESS_DETACH:
		unhookSend();
		unhookRecv();
		stopLogger();
		break;
	case DLL_THREAD_ATTACH:
	case DLL_THREAD_DETACH:
		break;
	}

	return TRUE;
}
