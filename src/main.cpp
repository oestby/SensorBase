#include <string>
#include <iostream>
#include "Tools/Logger.hpp"
#include "Tools/Time.hpp"
#include "serial/serial.h"

constexpr char TEMP_PORT[] = "/dev/USB0";

int main() {
    tools::Logger logger("logs/main.log");

    try {
        serial::Serial temp_sensor(TEMP_PORT);
    }
    catch(std::exception& e) {
        logger.error(e.what());
        std::cout << e.what() << std::endl;
    }
    
}
