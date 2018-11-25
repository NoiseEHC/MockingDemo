#pragma once

class IFileHandler
{
public:
    virtual std::unique_ptr<std::ostream> OpenOutput() const = 0;
    virtual void FinishOutput(std::ostream& file) const = 0;
};

class FileHandler final : public IFileHandler
{
public:
    explicit FileHandler(std::string directory);
    std::unique_ptr<std::ostream> OpenOutput() const override;
    void FinishOutput(std::ostream& file) const override;

private:
    std::string _directory;
};
