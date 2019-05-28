#pragma once

const BYTE _ASM_OP_PUSHAD = 0x60;
const BYTE _ASM_OP_PUSHFD = 0x9C;
const BYTE _ASM_OP_POPAD = 0x61;
const BYTE _ASM_OP_POPFD = 0x9D;
const BYTE _ASM_OP_CALL = 0xE8;
const BYTE _ASM_OP_JMP = 0xE9;
const BYTE _ASM_OP_NOP = 0x90;
const BYTE _ASM_OP_RET = 0xC3;

bool hookFunction(LPVOID originalFunction, LPVOID customFunction);
bool unhookFunction(LPVOID originalFunction);