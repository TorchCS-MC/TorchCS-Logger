#include <iostream>
#include <torchcs_logger/logger_manager.hpp>
#include <torchcs_logger/log_level.hpp>
#include <torchcs_logger/log_color.hpp>
#include <torchcs_logger/logger_options.hpp>


int main() {

    LoggerOptions options;
    options.setLogPath("Logs");

    LoggerManager logger("SERVER");

    //logger.info("Hello World", "Hello World");

    logger.load_options(options);
    logger.info("Hello", "Hello World");

    logger.file_logging(true);



    auto test = LoggerManager::getInstance("SERVER");

    logger.info("Hello", LogColor::DARK_BLUE + "Hello Wddddddddorld");

    return 0;
}
