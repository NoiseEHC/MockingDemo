#pragma once

class FileHandler final
{
public:
    explicit FileHandler(std::string directory);
    std::ofstream OpenOutput() const;
    void FinishOutput(std::ofstream& file) const;

private:
    std::string _directory;
};
