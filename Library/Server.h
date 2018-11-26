#pragma once

#include "CommunicationThread.h"
#include "FileHandler.h"

class Server final
{
    friend class FriendClass;

public:
    explicit Server(std::unique_ptr<IFileHandler> fileHandler, std::unique_ptr<ICommunicationThread> communicationThread);
    void Stop();

    static std::unique_ptr<Server> Create();

private:
    std::vector<std::string> _lines;
    std::unique_ptr<ICommunicationThread> _communicationThread;
    std::unique_ptr<IFileHandler> _fileHandler;

    void SaveLines();
    void ProcessLine(std::string const& line);
};
