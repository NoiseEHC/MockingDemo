#pragma once

#include <functional>

class Server;
class FileHandler;

class FriendClass
{
public:
    static std::function<void(std::string const&)> GetProcessLine(Server& server);
    static FileHandler& GetFileHandler(Server& server);
};
