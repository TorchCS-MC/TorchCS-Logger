#include <torchcs_logger/logger_options.hpp>

void LoggerOptions::setLogPath(fs::path path) {
    log_path = path;
}

fs::path LoggerOptions::getLogPath() {
    return log_path;
}