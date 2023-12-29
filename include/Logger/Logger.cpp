#include "Logger.h"
#include <iostream>


    Logger::LoggerClass::LoggerClass()
    {
        loggingState = 2;
        loggingConsole = true;
        fileLocation = "log.log";
    } // constructor

    Logger::LoggerClass::LoggerClass(int state, bool console, std::string& location)
    {
        loggingState = state;
        loggingConsole = console;
        fileLocation = location;
    } // constructor

    void Logger::LoggerClass::setLoggingState(int state)
    {
        loggingState = state;
    } // set logging state (0 - none, 1 - warning, 2 - info, 3 - debug)

    void Logger::LoggerClass::log(std::string &message, int state)
    {
        if (state <= loggingState)
        {
            if (loggingConsole)
            {
                std::string stateString;

                switch (loggingState)
                {
                    case 0:
                        system("Color 07");
                        break;
                    case 1:
                        system("Color 04");
                        stateString = "WARNING";
                        break;
                    case 2:
                        system("Color 07");
                        stateString = "INFO";
                        break;
                    case 3:
                        system("Color 01");
                        stateString = "DEBUG";
                        break;
                    default:
                        system("Color 04");
                        stateString = "WARNING";
                        break;
                }
                std::cout << stateString << ": "  << message << std::endl;
                system("Color 07");
            }
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


