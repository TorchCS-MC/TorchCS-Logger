#ifndef TORCHCS_LOGGER_LOGGEROPTIONS_H
#define TORCHCS_LOGGER_LOGGEROPTIONS_H

#include <filesystem>

namespace fs = std::filesystem;

class LoggerOptions {
private:
    fs::path log_path;

public:
    void setLogPath(fs::path path);
    fs::path getLogPath();

};


#endif
