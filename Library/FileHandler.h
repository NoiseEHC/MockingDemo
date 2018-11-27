#pragma once

class FileHandler
{
public:
    explicit FileHandler(std::string directory);

    FileHandler(FileHandler const&) = default;
    FileHandler& operator=(FileHandler const&) = default;
    FileHandler(FileHandler&&) noexcept = default;
    FileHandler& operator=(FileHandler&&) noexcept = default;

    virtual ~FileHandler() = default;
    virtual std::unique_ptr<std::ostream> OpenOutput() const;
    virtual void FinishOutput(std::ostream& file) const;

private:
    std::string _directory;
};
