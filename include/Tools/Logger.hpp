#ifndef LOGGER_HPP
#define LOGGER_HPP

#include <string>
#include <fstream>
#include <iostream>

#include <Tools/Time.hpp>
namespace tools {
class Logger {
    public:
        Logger(std::string log_file = "log.log");
        ~Logger();

        // I want this to be a singleton
        Logger(const Logger&) = delete;
        Logger& operator=(const Logger&) = delete;

        //One member function for each type of logging level.
        void debug(std::string msg);
        void info(std::string msg);
        void warn(std::string msg);
        void error(std::string msg);
        std::string getLogFileName(void);
        void setLogFileName(std::string new_name);

    private:
        std::ofstream stream;
        std::string logfile_name;
        Time timer;
};
} //namespace tools
#endif //LOGGER_HPP

