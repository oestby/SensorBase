#include <MOSI/MOSI.hpp>

MOSIClass::MOSIClass(int out_pin, int in_pin, int clk_pin, int ss_pin):
    out_pin(out_pin), in_pin(in_pin), clk_pin(clk_pin), ss_pin(ss_pin)
{
    in = GPIO(in_pin, io::IN);
    out = GPIO(out_pin, io::OUT);
    clk_pin = GPIO(clk_pin, io::OUT);
    ss_pin = GPIO(ss_pin, io::OUT);
}

MOSIClass::~MOSIClass() {
    in.deexportPin();
    out.deexportPin();
    clk.deexportPin();
    ss.deexportPin();
}

char* writeData(const char* msg, size_t size) {


}

