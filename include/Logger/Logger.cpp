#include "Logger.h"
#include <iostream>

#include <ctime>


Logger::LoggerClass::LoggerClass()
{
    loggingState = 2;
    loggingConsole = true;
    fileLocation = "log.log";
} // constructor

Logger::LoggerClass::LoggerClass(int state, bool console, std::string &location)
{
    loggingState = state;
    loggingConsole = console;
    fileLocation = location;
} // constructor

void Logger::LoggerClass::setLoggingState(int state)
{
    loggingState = state;
} // set logging state (0 - none, 1 - warning, 2 - info, 3 - debug)

void Logger::LoggerClass::log(std::string message, int state)
{
    if (state <= loggingState)
    {
        // Create Log message
        std::string logMessage;

        //Get current time in format "DD.MM.YYYY HH:MM"
        time_t now;
        time(&now);

        char date_time[20];
        struct tm *time_info;

        time_info = localtime(&now);

        strftime(date_time, sizeof(date_time), "%d.%m.%Y %H:%M", time_info);

        logMessage.append(date_time).append(" ");

        switch (state)
        {
            case 1:
                logMessage += "WARNING";
                break;
            case 2:
                logMessage += "INFO";
                break;
            case 3:
                logMessage += "DEBUG";
                break;
            default:
                logMessage += "INFO";
                break;
        }

        logMessage.append(": ").append(message);

        // Logging to console
        if (loggingConsole)
        {
            std::cout << logMessage << std::endl;
        }

        // Loggin to file
        logFile.open(fileLocation, std::ios::app);
        logFile << logMessage << std::endl;
        logFile.close();

    }

} // log message with state

void Logger::LoggerClass::setFileLocation(std::string &location)
{
    if (location.empty())
    {
        location = "log.log";
    }
    fileLocation = location;
} // set file location

void Logger::LoggerClass::setLoggingConsole(bool state)
{
    loggingConsole = state;
} // set logging to terminal


