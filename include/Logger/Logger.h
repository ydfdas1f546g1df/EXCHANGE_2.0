#ifndef EXCHANGE2_0_MTAS_LOGGER_H
#define EXCHANGE2_0_MTAS_LOGGER_H

#include <string>

namespace Logger
{
    class LoggerClass
    {
    private:
        int loggingState;
        bool loggingConsole;
        std::string fileLocation;
    public:
        LoggerClass(); // constructor
        LoggerClass(int state, bool console, std::string &location); // constructor

        void setLoggingState(int state); // set logging state (0 - none, 1 - warning, 2 - info, 3 - debug)
        void log(std::string &message, int state); // log message with state
        void setFileLocation(std::string &location); // set file location
        void setLoggingConsole(bool state = true); // set logging to terminal
    };// initialize logger

}
#endif //EXCHANGE2_0_MTAS_LOGGER_H
