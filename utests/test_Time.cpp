#include <Tools/Time.hpp>
#include <iostream>
#include <thread>
#include <chrono>

using namespace tools;

int main() {
    Time timer;
    std::cout << std::fixed;

    std::cout << "Start time: " << timer.getStartTime() << std::endl;
    std::cout << "Current time: " << timer.getCurrentTime() << std::endl;

    std::cout << "String time format: " << timer.getCurrentTimeString() << std::endl;

    std::cout << "Start time: " << timer.getStartTime() << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(2));
    std::cout << "Runtime after 2 sec: " << timer.getRunTime() << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(4));
    std::cout << "Runtime after 6 sec: " << timer.getRunTime() << std::endl;

}


