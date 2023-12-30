#ifndef EXCHANGE2_0_MTAS_LOGGER_H
#define EXCHANGE2_0_MTAS_LOGGER_H

#include <string>
#include <fstream>

namespace Logger
{

    struct states{
            static const int none = 0;
            static const int warning = 1;
            static const int info = 2;
            static const int debug = 3;
        };

    class LoggerClass
    {
    private:
        std::ofstream logFile;
        int loggingState;
        bool loggingConsole;
        std::string fileLocation;
    public:

        LoggerClass(); // constructor
        LoggerClass(int state, bool console, std::string &location); // constructor

        void setLoggingState(int state); // set logging state (0 - none, 1 - warning, 2 - info, 3 - debug)
        void log(std::string message, int state = 2); // log message with state
        void setFileLocation(std::string &location); // set file location
        void setLoggingConsole(bool state = true); // set logging to terminal
    };// initialize logger

}
#endif //EXCHANGE2_0_MTAS_LOGGER_H
