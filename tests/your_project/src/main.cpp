#include <torchcs_logger/custom_formatter.hpp>
#include <torchcs_logger/logger_manager.hpp>
#include <torchcs_logger/logger_options.hpp>


int main() {

    LoggerOptions options;

    options.setLogPath("logger/logs");
    
    LoggerManager logger("Server");
    logger.file_logging(true);

    logger.load_options(options);

    logger.info("Player", "Hello");

    return 0;
}