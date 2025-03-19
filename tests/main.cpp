#include <iostream>
#include <LoggerManager.hpp>
#include <LoggerOptions.hpp>

#include <LogColor.hpp>

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
