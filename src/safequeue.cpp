#include <windows.h>
#include "safequeue.h"


SafeQueue::SafeQueue()
{
    m_ghMutex = CreateMutex(nullptr, FALSE, nullptr);
}


SafeQueue::~SafeQueue()
{
    CloseHandle(m_ghMutex);
}

void SafeQueue::push(char* packet)
{
    char* szPacket;
    size_t len;

    len = strlen(packet);
    szPacket = (char*)malloc(len + 1);
    snprintf(szPacket, len + 1, packet);

    WaitForSingleObject(m_ghMutex, INFINITE);
    m_Queue.push(szPacket);
    ReleaseMutex(m_ghMutex);
}

void SafeQueue::pop()
{
    char* szPacket;

    WaitForSingleObject(m_ghMutex, INFINITE);
    szPacket = this->m_Queue.front();
    m_Queue.pop();
    free(szPacket);
    ReleaseMutex(m_ghMutex);
}

char* SafeQueue::front()
{
    char* packet;

    WaitForSingleObject(m_ghMutex, INFINITE);
    packet = m_Queue.front();
    ReleaseMutex(m_ghMutex);

    return packet;
}

bool SafeQueue::empty()
{
    bool bEmpty;

    WaitForSingleObject(m_ghMutex, INFINITE);
    bEmpty = m_Queue.empty();
    ReleaseMutex(m_ghMutex);

    return bEmpty;
}
