#pragma once

#include <functional>

class Server;

class FriendClass
{
public:
    static std::function<void(std::string const&)> GetProcessLine(Server& server);
};
