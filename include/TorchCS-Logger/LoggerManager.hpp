#ifndef TORCHCS_LOGGER_LOGGERMANAGER_H
#define TORCHCS_LOGGER_LOGGERMANAGER_H

#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/sinks/basic_file_sink.h>

#include <memory>
#include <string>
#include <unordered_map>
#include <mutex>
#include <filesystem>

#include "LogLevel.hpp"
#include "LoggerOptions.hpp"

namespace fs = std::filesystem;

class LoggerManager {
private:
    static std::unordered_map<std::string, std::shared_ptr<LoggerManager>> instances;
    static std::mutex instance_mutex;

    std::shared_ptr<spdlog::logger> logger;

    bool is_file_logging = false;
    bool is_console_logging = true;

    fs::path file_logger_directory_path = "logs";

    void Log(LogLevel level, const std::string& key, const std::string& message);

public:
    static std::shared_ptr<LoggerManager> getInstance(const std::string& logArea = "GLOBAL");
    static bool createInstance(const std::string& logArea);
    static bool deleteInstance(const std::string& logArea);
    static bool existsInstance(const std::string& logArea);

    void load_options(LoggerOptions& options);

    void file_logging(bool on);
    void console_logging(bool on);

    void flush_every(std::chrono::seconds interval);
    void flush_on(LogLevel level);

    void info(const std::string& key, const std::string& message);
    void verbose(const std::string& key, const std::string& message);
    void warn(const std::string& key, const std::string& message);
    void error(const std::string& key, const std::string& message);
    void critical(const std::string& key, const std::string& message);
    void debug(const std::string& key, const std::string& message);

    explicit LoggerManager(const std::string& logArea);
};

#endif
