#include "stdafx.h"
#include "memscan.h"

LPVOID findPattern(BYTE* pattern, char* mask, DWORD length)
{
	DWORD imageEnd = IMAGE_BASE + IMAGE_SIZE - length;
	DWORD i, j;

	// Scan the whole image for the pattern
	for (j = IMAGE_BASE; j < imageEnd; ++j)
	{
		// If the pattern is found, return the address where it begins
		for (i = 0; i < length && (mask[i] == '?' || *(BYTE*)(j + i) == pattern[i]); ++i);
		if (i == length) return (LPVOID)j;
	}

	return nullptr;
}