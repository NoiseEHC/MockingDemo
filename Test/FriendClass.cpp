#include "pch.h"
#include "FriendClass.h"
#include "Server.h"

using namespace std;
using namespace placeholders;

function<void(string const&)> FriendClass::GetProcessLine(Server& server)
{
	return bind(&Server::ProcessLine, &server, _1);
}
