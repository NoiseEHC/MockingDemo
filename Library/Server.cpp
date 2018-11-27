#include "pch.h"
#include "Server.h"

using namespace std;
using namespace placeholders;

Server::Server(FileHandler fileHandler, unique_ptr<CommunicationThread> communicationThread):
    _communicationThread{move(communicationThread)},
    _fileHandler{move(fileHandler)}
{
    _communicationThread->Start(bind(&Server::ProcessLine, this, _1));
}

void Server::Stop()
{
    _communicationThread->Stop();
    SaveLines();
}

void Server::SaveLines()
{
    auto const file = _fileHandler.OpenOutput();

    for (auto const& s : _lines)
        *file << s << "\n";
    _lines.clear();

    _fileHandler.FinishOutput(*file);
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
		FileHandler{"c:/temp"},
        make_unique<CommunicationThread>()
    );
}
