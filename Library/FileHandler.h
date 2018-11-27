#pragma once

class FileHandler FINAL
{
public:
    explicit FileHandler(std::string directory);

    MOCKABLE std::unique_ptr<std::ostream> OpenOutput() const;
    MOCKABLE void FinishOutput(std::ostream& file) const;

private:
    std::string _directory;
};
