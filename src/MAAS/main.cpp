#include <iostream>
#include <fstream>
#include <string>
#include "Logger/Logger.h"


#define LOGFILE "MMAS.log"
#define PORT 5050



int main()
{
    std::string logFile = LOGFILE;

    Logger::LoggerClass logger(Logger::states::debug, true, logFile);

    logger.log("Hello World!", Logger::states::info);
    logger.log("Hello World!", Logger::states::debug);

return 0;
};