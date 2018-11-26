#include "pch.h"
#include "CommunicationThread.h"

using namespace std;

CommunicationThread::CommunicationThread():
    _exit{false}
{
}

CommunicationThread::~CommunicationThread()
{
    Stop();
}

void CommunicationThread::Start(function<void(string)> callback)
{
    _callback = move(callback);
    _workThread = thread{bind(&CommunicationThread::ThreadProc, this)};
}

void CommunicationThread::Stop()
{
    _exit.store(true, memory_order_relaxed);
    if (_workThread.joinable())
        _workThread.join();
}

void CommunicationThread::ThreadProc() const
{
    uint64_t counter = 1;
    for (;;)
    {
        if (_exit.load(memory_order_relaxed))
            break;

        _callback(fmt::format("LINE {}", counter));
        ++counter;

        this_thread::sleep_for(1s);
    }
}
