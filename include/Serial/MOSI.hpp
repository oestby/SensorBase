#ifndef MOSI_HPP
#define MOSI_HPP

#include <GPIO/GPIO.hpp>

class MOSIClass {
    public:
        MOSIClass(int out_pin, int in_pin, int clk_pin, int ss_pin);
        ~MOSIClass();
        void writeData(const char* msg, size_t size);
        char* receiveData();

    private:
        GPIO in, out, clk, ss;
        int in_pin, out_pin, clk_pin, ss_pin;

};

#endif //MOSI_HPP
