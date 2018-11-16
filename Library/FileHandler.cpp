#include "pch.h"
#include "FileHandler.h"

using namespace std;

FileHandler::FileHandler(string directory): _directory{move(directory)}
{
}

ofstream FileHandler::OpenOutput() const
{
    auto const fileName = fmt::format("{}/file.txt", _directory);
    return ofstream{fileName};
    // Imagine returning a temporary, delete-on-close file.
}

// ReSharper disable once CppMemberFunctionMayBeStatic
void FileHandler::FinishOutput(ofstream& file) const
{
    file.flush();
    file.close();
    // Imagine renaming the file to the final name 
    // (and deleting the old file) in a transaction.
}
