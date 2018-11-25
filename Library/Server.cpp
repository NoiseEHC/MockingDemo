#include "pch.h"
#include "Server.h"

using namespace std;
using namespace placeholders;

Server::Server(unique_ptr<IFileHandler> fileHandler):
    _communicationThread{bind(&Server::ProcessLine, this, _1)},
    _fileHandler{move(fileHandler)}
{
}

void Server::Stop()
{
    _communicationThread.Stop();
    SaveLines();
}

void Server::SaveLines()
{
    auto const file = _fileHandler->OpenOutput();

    for (auto const& s : _lines)
        *file << s << "\n";
    _lines.clear();

    _fileHandler->FinishOutput(*file);
}

void Server::ProcessLine(string const& line)
{
    _lines.emplace_back(line);
    if (_lines.size() >= 5)
        SaveLines();
}

unique_ptr<Server> Server::Create()
{
    return make_unique<Server>(
        make_unique<FileHandler>("c:/temp")
    );
}
