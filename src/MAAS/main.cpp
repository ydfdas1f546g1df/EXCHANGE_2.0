#include <iostream>
#include <fstream>
#include <string>
#include "Logger/Logger.h"


#define LOGFILE "MMAS.log"
#define PORT 5050



int main()
{
    Logger::LoggerClass logger;

    logger.log((std::string &) "Hello World!", 2);

return 0;
};