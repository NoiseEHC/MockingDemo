#pragma once

#include <functional>

class CommunicationThread FINAL
{
public:
    explicit CommunicationThread();
    MOCKABLE ~CommunicationThread();
    MOCKABLE void Start(std::function<void(std::string)> callback);
    MOCKABLE void Stop();

private:
    std::function<void(std::string)> _callback;
    std::atomic<bool> _exit;
    std::thread _workThread;

    void ThreadProc() const;
};
