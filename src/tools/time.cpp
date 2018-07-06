#include <tools/time.hpp>
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

std::string Time::getCurrentTimeString(void) const {
    time_t now;
    time(&now);
    std::string str = formatTimeISO(now);
    return str;
}

std::string Time::getStartTimeString(void) const {
    std::string str = formatTimeISO(start_time);
    return str;
}

std::string Time::formatTimeISO(time_t current_time) const {
    using std::to_string;
    struct tm now = *localtime(&current_time);

    std::string time_str = to_string(now.tm_year + 1900) + "-";
    if(now.tm_mon < 10) {
        time_str += "0";
    }
    time_str += to_string(now.tm_mon + 1) + "-";
    if(now.tm_mday < 10) {
        time_str += "0";
    }
    time_str += to_string(now.tm_mday) + " ";
    if(now.tm_hour < 10) {
        time_str += "0";
    }
    time_str += to_string(now.tm_hour) + ":";
    if(now.tm_min < 10) {
        time_str += "0";
    }
    time_str += to_string(now.tm_min) + ":";
    if(now.tm_sec < 10) {
        time_str += "0";
    }
    time_str += to_string(now.tm_sec);
    return time_str;
}

