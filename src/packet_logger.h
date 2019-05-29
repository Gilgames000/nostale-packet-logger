#pragma once


const BYTE SEND_PATTERN[] = "\x53\x56\x8B\xF2\x8B\xD8\xEB\x04";
const BYTE RECV_PATTERN[] = "\x55\x8B\xEC\x83\xC4\xF4\x53\x56\x57\x33\xC9\x89\x4D\xF4\x89\x55\xFC\x8B\xD8\x8B\x45\xFC";
const char SEND_MASK[] = "xxxxxxxx";
const char RECV_MASK[] = "xxxxxxxxxxxxxxxxxxxxxx";
const DWORD SEND_LEN = 8;
const DWORD RECV_LEN = 22;

bool findAddresses();
void startLogger();
void stopLogger();
bool hookSend();
bool hookRecv();
bool unhookSend();
bool unhookRecv();