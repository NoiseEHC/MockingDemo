#include "pch.h"
#include "Server.h"

using namespace std;

int main()
{
    cout << "Starting server.\n";
    Server obj{};
    cout << "Press ENTER to shut-down.\n";
    getchar();
    cout << "Stopping server.\n";
    obj.Stop();
    cout << "Server stopped.\n";
}
