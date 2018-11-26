#pragma once

#include <functional>

class ICommunicationThread
{
public:
    virtual ~ICommunicationThread() = default;
    virtual void Start(std::function<void(std::string)> callback) = 0;
    virtual void Stop() = 0;
};

class CommunicationThread final : public ICommunicationThread
{
public:
    explicit CommunicationThread();
    ~CommunicationThread();
    void Start(std::function<void(std::string)> callback) override;
    void Stop() override;

private:
    std::function<void(std::string)> _callback;
    std::atomic<bool> _exit;
    std::thread _workThread;

    void ThreadProc() const;
};
