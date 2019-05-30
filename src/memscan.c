#include <windows.h>
#include "memscan.h"


LPVOID FindPattern(const BYTE *lpPattern, LPCSTR szMask)
{
    DWORD dwLength = strlen(szMask);
    DWORD dwImageEnd = IMAGE_BASE + IMAGE_SIZE - dwLength;
    DWORD_PTR i, j;

    // Scan the whole image for the pattern
    for (j = IMAGE_BASE; j < dwImageEnd; ++j)
    {
        // If the pattern is found, return the address at which it begins
        for (i = 0; i < dwLength && (szMask[i] == '?' || *(BYTE*)(j + i) == lpPattern[i]); ++i);
        if (i == dwLength) return j;
    }

    return NULL;
}