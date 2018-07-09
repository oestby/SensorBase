#include <tools/time.hpp>
#include <memory>
#include <iostream>
using namespace tools;
Time::Time():
    start_time(time(nullptr))
{
    //Empty by choice
}

double Time::getRunTime(void) const {
    time_t current_time;
    time(&current_time);
    double runtime = difftime(current_time, start_time);
    return runtime;
}

double Time::getStartTime(void) const {
    return static_cast<double>(start_time);
}

double Time::getCurrentTime(void) const {
    time_t now;
    time(&now);
    return static_cast<double>(now);
}

std::string Time::getCurrentTimestamp(void) const {
    time_t now;
    time(&now);
    std::string str = formatTimeISO(now);
    return str;
}

std::string Time::getStartTimestamp(void) const {
    std::string str = formatTimeISO(start_time);
    return str;
}

std::string Time::formatTimeISO(time_t current_time) const {
    struct tm now = *localtime(&current_time);
    char buffer[40];
    strftime(buffer, 40, "%F %T", &now);
    std::string time(buffer);

    return time;
}

