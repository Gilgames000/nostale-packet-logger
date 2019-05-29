#pragma once


const DWORD IMAGE_BASE = 0x00401000; // Default location; NosTale doesn't use ASLR
const DWORD IMAGE_SIZE = 0x002CC000;

LPVOID findPattern(BYTE* pattern, char* mask, DWORD length);