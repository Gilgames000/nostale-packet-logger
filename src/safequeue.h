#pragma once
#include <queue>

class SafeQueue
{
private:
    HANDLE m_ghMutex;
    std::queue<char*> m_Queue;

public:
    SafeQueue();
    ~SafeQueue();
    void push(char* packet);
    void pop();
    char* front();
    bool empty();
};

