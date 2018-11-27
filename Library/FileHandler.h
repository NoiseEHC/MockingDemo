#pragma once

class FileHandler
{
public:
    explicit FileHandler(std::string directory);

    virtual std::unique_ptr<std::ostream> OpenOutput() const;
    virtual void FinishOutput(std::ostream& file) const;

private:
    std::string _directory;
};
