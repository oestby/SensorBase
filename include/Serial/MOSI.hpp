#ifndef MOSI_HPP
#define MOSI_HPP

#include <GPIO/GPIO.hpp>
#include <array>
#include <thread>
#include <chrono>

/*! MOSI Class for serial communication
 * 
 * This class is created to handle serial communication using MOSI.
 *
 */

constexpr int SPI_DELAY_TIME = 10000; ///The time the MCU takes between bits.

using namespace gpio;

class MOSITest;

class MOSIClass {
    public:
        MOSIClass(int in_pin, int out_pin, int clk_pin, int ss_pin);
        ~MOSIClass();
        char writeData(char msg);

    private:
        std::array<int, 8> extractBits(char data);
        char parseBits(std::array<int, 8> bits);
        GPIO in, out, clk, ss;
        int in_pin, out_pin, clk_pin, ss_pin;

    friend MOSITest;

};

#endif //MOSI_HPP

