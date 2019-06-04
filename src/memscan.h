#pragma once

#define IMAGE_BASE 0x00400000   // Default location; NosTale doesn't use ASLR
#define IMAGE_SIZE 0x004B4FFF

LPVOID FindPattern(const BYTE *lpPattern, LPCSTR szMask);