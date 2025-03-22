#include <TorchCS-Logger/LoggerOptions.hpp>

void LoggerOptions::setLogPath(fs::path path) {
    log_path = path;
}

fs::path LoggerOptions::getLogPath() {
    return log_path;
}