#include "pch.h"
#include "Server.h"
#include "FriendClass.h"
#include <catch.hpp>
#include <fakeit.hpp>

using namespace std;
using namespace fakeit;

TEST_CASE("Test the file handling")
{
    Mock<IFileHandler> mockHandler{};
    When(Method(mockHandler,OpenOutput)).AlwaysDo([]() { return make_unique<ostringstream>(); });
    Fake(Method(mockHandler,FinishOutput));
    Fake(Dtor(mockHandler));

    Server sut{unique_ptr<IFileHandler>{&mockHandler.get()}};
    auto const processLine = FriendClass::GetProcessLine(sut);

    processLine("1");
    processLine("2");
    processLine("3");
    processLine("4");
    processLine("5");

    Verify(Method(mockHandler,OpenOutput)).Once();
}
