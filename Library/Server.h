#pragma once

#include "CommunicationThread.h"
#include "FileHandler.h"

class Server final
{
public:
    explicit Server();
    void Stop();

private:
    std::vector<std::string> _lines;
    CommunicationThread _communicationThread;
    FileHandler _fileHandler;

    void SaveLines();
    void ProcessLine(std::string const& line);
};
