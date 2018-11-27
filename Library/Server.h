#pragma once

#include "CommunicationThread.h"
#include "FileHandler.h"

class Server final
{
    friend class FriendClass;

public:
    explicit Server(FileHandler fileHandler, std::unique_ptr<CommunicationThread> communicationThread);
    void Stop();

    static std::unique_ptr<Server> Create();

private:
    std::vector<std::string> _lines;
    std::unique_ptr<CommunicationThread> _communicationThread;
    FileHandler _fileHandler;

    void SaveLines();
    void ProcessLine(std::string const& line);
};
