#pragma once

// Default location; NosTale doesn't use ASLR
#define IMAGE_BASE 0x00401000
#define IMAGE_SIZE 0x002CC000

LPVOID FindPattern(const BYTE *lpPattern, LPCSTR szMask);