#ifndef TIME_HPP
#define TIME_HPP

#include <ctime>
#include <string>
namespace tools {
class Time {
public:
    Time();
        
    Time(const Time&) = delete;
    Time& operator=(const Time&) = delete;

    double getRunTime(void) const;
    double getStartTime(void) const; 
    double getCurrentTime(void) const; 
    std::string getCurrentTimeString(void) const;
    std::string getStartTimeString(void) const; 
private:
    time_t start_time;
    //Formats and returns a time to a ISO standard string
    std::string formatTimeISO(time_t current_time) const; 
};
} //namespace tools

#endif

