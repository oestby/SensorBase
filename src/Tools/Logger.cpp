#include <Tools/Logger.hpp>
using namespace tools;
Logger::Logger(std::string log_file):
    logfile_name(log_file), timer() 
{
    info("Logger created.");
}

void Logger::debug(std::string msg) {
    stream.open(logfile_name, std::ofstream::ate | std::ofstream::app);
    stream << "\e[32m\e[1m[DEBUG] [" << timer.getCurrentTimeString() << "]:\e[0m "<< msg << std::endl;
    stream.close();
}
void Logger::info(std::string msg) {
    stream.open(logfile_name, std::ofstream::ate | std::ofstream::app);
    stream << "\e[34m\e[1m[INFO] ["<< timer.getCurrentTimeString() << "]:\e[0m "  << msg << std::endl;
    stream.close();
}
void Logger::warn(std::string msg) {
    stream.open(logfile_name, std::ofstream::ate | std::ofstream::app);
    stream << "\e[33m\e[1m[WARNING] [" << timer.getCurrentTimeString() << "]:\e[0m " << msg << std::endl;
    stream.close();
}

void Logger::error(std::string msg) {
    stream.open(logfile_name, std::ofstream::ate | std::ofstream::app);
    stream << "\e[31m\e[1m[ERROR] [" << timer.getCurrentTimeString() << "]:\e[0m " << msg << std::endl;
    stream.close();
}
        
std::string Logger::getLogFileName(void) {
    return logfile_name;
}

void Logger::setLogFileName(std::string new_name) {
    logfile_name = new_name;
}

