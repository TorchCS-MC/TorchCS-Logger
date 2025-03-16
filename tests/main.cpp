#include <iostream>
#include <LoggerManager.hpp>
#include <LoggerOptions.hpp>

#include <LogColor.hpp>

int main() {

    LoggerOptions options;

    options.setLogPath("Logs");

    LoggerManager logger("SERVER");

    logger.load_options(options);

    logger.file_logging(true);

    logger.info("TEST", LogColor::BLUE + "Hello World");

    logger.info("dedicated::start", "§8[§6Stay§eCation§8]§7 Hello World");

    logger.info("dedicated::start", "§8[§6Stay§eCation§8]§7 Hello World");

    logger.info("dedicated::stop", "§8[§6Stay§eCation§8]§7 Hello World");
    logger.info("dedicated::cool", "§8[§6Stay§eCation§8]§7 Hello World");



    return 0;
}
