#include <SDKDDKVer.h>
#include <windows.h>
#include <stdio.h>
#include "packet_logger.h"


BOOL APIENTRY DllMain(HMODULE hModule, DWORD fdwReason, LPVOID lpvReserved);
DWORD WINAPI UnloadDll(LPVOID lpParameter);

DWORD WINAPI UnloadDll(LPVOID hModule) {

    printf("[INFO]: Press VK_END to unload the dll\n");
    while (1)
    {
        if (GetAsyncKeyState(VK_END) & 1)
        {
            printf("[INFO]: VK_END pressed; unloading the dll...\n");
            FreeLibraryAndExitThread((HMODULE)hModule, 0);
        }
    }
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD  fdwReason, LPVOID lpvReserved)
{
    switch (fdwReason)
    {
    case DLL_PROCESS_ATTACH:
        StartLogger();
        if (FindAddresses() && HookSend() && HookRecv())
            CreateThread(NULL, 0, UnloadDll, hModule, 0, NULL);
        else return FALSE;
        break;
    case DLL_PROCESS_DETACH:
        UnhookSend();
        UnhookRecv();
        StopLogger();
        break;
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
        break;
    }

    return TRUE;
}
