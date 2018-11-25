#include "pch.h"
#include "Server.h"
#include <catch.hpp>
#include <fakeit.hpp>

using namespace std;
using namespace fakeit;

TEST_CASE("Test the file handling")
{
    Mock<IFileHandler> mockHandler{};
    When(Method(mockHandler,OpenOutput)).AlwaysDo([]() { return unique_ptr<ostream>{}; });

    Server sut{unique_ptr<IFileHandler>{&mockHandler.get()}};
}
