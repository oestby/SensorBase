#ifndef MOSI_HPP
#define MOSI_HPP

#include <serial/GPIO.hpp>
#include <array>
#include <thread>
#include <chrono>

namespace serial {
///@param SPI_DELAY_TIME The time the MCU takes between bits.
constexpr int SPI_DELAY_TIME        = 10000; 
///The delay needed for the slave to be ready to send.
constexpr int SPI_SLAVE_READY_DELAY = 10000;
///There should be a way to change the word size of the AVR with one variable
constexpr int AVR_WORD_SIZE         = 8;


using namespace serial::gpio;

class MOSITest;

/*! MOSI Class for serial communication
 * 
 * This class is created to handle serial communication using MOSI.
 *
 * @param out   This pin is the MOSI pin.
 * @param in    This is the pin used as MISO.
 * @param clk   This is the clock signal pin.
 * @param ss    This is the slave select pin.
 */
class MOSIClass {
    public:
        ///Constructs a MOSI object for serial communication
        MOSIClass(int in_pin, int out_pin, int clk_pin, int ss_pin);
        ~MOSIClass();
        
        ///MOSI both writes and reads at the same time, so it will write
        ///the msg to the slave and return the read data from the slave.
        char writeData(char msg);

    private:
        ///Initializes the slave.
        void initSlave(void);
        ///Takes a word and translates it into an array of the bits of the word.
        std::array<int, 8> extractBits(char data);
        ///Takes in a bit array and turns it back into a char
        char parseBits(std::array<int, 8> bits);
        int in_pin, out_pin, clk_pin, ss_pin;
        GPIO in, out, clk, ss;
        
    friend MOSITest;

};
} //namespace serial

#endif //MOSI_HPP

