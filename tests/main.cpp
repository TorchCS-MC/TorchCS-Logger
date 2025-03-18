#include <iostream>
#include <LoggerManager.hpp>
#include <LoggerOptions.hpp>

#include <LogColor.hpp>

int main() {

    LoggerOptions options;

    options.setLogPath("Logs");

    LoggerManager logger("SERVER");
    logger.load_options(options);
    logger.info("Hello", "Hello World");

    logger.console_logging(false);

    auto test = LoggerManager::getInstance("SERVER");


    logger.info("Hello", "Hello Wddddddddorld");





    return 0;
}
