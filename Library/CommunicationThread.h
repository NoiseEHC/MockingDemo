#pragma once

#include <functional>

class CommunicationThread
{
public:
    explicit CommunicationThread();
    virtual ~CommunicationThread();
    virtual void Start(std::function<void(std::string)> callback);
    virtual void Stop();

private:
    std::function<void(std::string)> _callback;
    std::atomic<bool> _exit;
    std::thread _workThread;

    void ThreadProc() const;
};
