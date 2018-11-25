#pragma once

#include "CommunicationThread.h"
#include "FileHandler.h"

class Server final
{
public:
    explicit Server(std::unique_ptr<IFileHandler> fileHandler);
    void Stop();

    static std::unique_ptr<Server> Create();

private:
    std::vector<std::string> _lines;
    CommunicationThread _communicationThread;
    std::unique_ptr<IFileHandler> _fileHandler;

    void SaveLines();
    void ProcessLine(std::string const& line);
};
