#include "pch.h"
#include "FileHandler.h"

using namespace std;

FileHandler::FileHandler(string directory): _directory{move(directory)}
{
}

unique_ptr<ostream> FileHandler::OpenOutput() const
{
    auto const fileName = fmt::format("{}/file.txt", _directory);
    return make_unique<ofstream>(fileName);
    // Imagine returning a temporary, delete-on-close file.
}

// ReSharper disable once CppMemberFunctionMayBeStatic
void FileHandler::FinishOutput(ostream& file) const
{
    auto fs = dynamic_cast<ofstream*>(&file);
    if (fs)
    {
        fs->flush();
        fs->close();
    }
    // Imagine renaming the file to the final name 
    // (and deleting the old file) in a transaction.
}
