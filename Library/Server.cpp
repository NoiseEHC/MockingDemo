#include "pch.h"
#include "Server.h"

using namespace std;
using namespace placeholders;

Server::Server():
    _communicationThread{bind(&Server::ProcessLine, this, _1)},
    _fileHandler{"c:/temp"}
{
}

void Server::Stop()
{
    _communicationThread.Stop();
    SaveLines();
}

void Server::SaveLines()
{
    auto file = _fileHandler.OpenOutput();

    for (auto const& s : _lines)
        file << s << "\n";
    _lines.clear();

    _fileHandler.FinishOutput(file);
}

void Server::ProcessLine(string const& line)
{
    _lines.emplace_back(line);
    if (_lines.size() >= 5)
        SaveLines();
}
