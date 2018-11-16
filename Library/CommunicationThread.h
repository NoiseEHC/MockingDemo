#pragma once

#include <functional>

class CommunicationThread final
{
public:
    explicit CommunicationThread(std::function<void(std::string)> callback);
    ~CommunicationThread();
    void Stop();

private:
    std::function<void(std::string)> _callback;
    std::atomic<bool> _exit;
    std::thread _workThread;

    void ThreadProc() const;
};
