#include "pch.h"
#include "Server.h"
#include "FriendClass.h"
#include <catch.hpp>
#include <fakeit.hpp>

using namespace std;
using namespace fakeit;

TEST_CASE("Test the file handling")
{
    Mock<CommunicationThread> mockComm{};
    When(Method(mockComm,Start)).AlwaysDo([&](function<void(string)> callback) { ; });
    Fake(Method(mockComm,Stop));
    Fake(Dtor(mockComm));

    Server sut{FileHandler{"non-existent folder"}, unique_ptr<CommunicationThread>{&mockComm.get()}};

    Mock<FileHandler> mockHandler{FriendClass::GetFileHandler(sut)};
    When(Method(mockHandler,OpenOutput)).AlwaysDo([]() { return make_unique<ostringstream>(); });

    SECTION("Test SaveLines")
    {
        Fake(Method(mockHandler,FinishOutput));

        auto const processLine = FriendClass::GetProcessLine(sut);

        processLine("1");
        processLine("2");
        processLine("3");
        processLine("4");
        processLine("5");
    }

    SECTION("Stop saves remaining items")
    {
        string output;
        When(Method(mockHandler,FinishOutput)).AlwaysDo([&](ostream& file)
        {
            output = dynamic_cast<ostringstream&>(file).str();
        });

        auto const processLine = FriendClass::GetProcessLine(sut);

        processLine("1");
        processLine("2");
        processLine("3");

        sut.Stop();

        Verify(Method(mockComm,Stop)).Once();
        CHECK(count(begin(output), end(output), '\n') == 3);
    }

    Verify(Method(mockHandler,OpenOutput)).Once();
    Verify(Method(mockHandler,FinishOutput)).Once();
    Verify(Method(mockComm,Start)).Once();
}
