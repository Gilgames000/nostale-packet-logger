#pragma once


const DWORD SEND_ADDRESS = 0x004E5C68;
const DWORD RECV_ADDRESS = 0x004D6214;

void startLogger();
void stopLogger();
void hookSend();
void hookRecv();
void unhookSend();
void unhookRecv();