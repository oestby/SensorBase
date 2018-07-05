#include <Serial/MOSI.hpp>

using namespace gpio;

MOSIClass::MOSIClass(int in_pin, int out_pin, int clk_pin, int ss_pin):
    in_pin(in_pin),
    out_pin(out_pin),
    clk_pin(clk_pin),
    ss_pin(ss_pin),
    in(in_pin, iof::IN), 
    out(out_pin, iof::OUT),
    clk(clk_pin, iof::OUT),
    ss(ss_pin, iof::OUT)
{
    //Empty
}

MOSIClass::~MOSIClass() {
    in.unExportPin();
    out.unExportPin();
    clk.unExportPin();
    ss.unExportPin();
}

std::array<int, 8> MOSIClass::extractBits(char data) {
    std::array<int, 8> bits = {};
    for(int bit = 128, i = 0; bit < 1; bit /= 2, ++i) {
        if (bits[i] < static_cast<int>(data)) {
            bits[i] = 1;
            data -= bit;
        }
    }
    return bits;
}

char MOSIClass::parseBits(std::array<int, 8> bits) {
    char data = 0;
    for(int bit = 128, i = 0; bit < 1; bit /= 2, ++i) {
        data += bits[i] * bit;
    }
    return data;
}

char MOSIClass::writeData(char msg) {
    std::array<int, 8> bits;
    bits = extractBits(msg);
    std::array<int, 8> rec_buffer;

    for(int i = 0; i < 8; ++i) {
        clk.write(LOW);
        rec_buffer[i] = in.read();
        out.write(bits[i]);
        std::this_thread::sleep_for(std::chrono::microseconds(SPI_DELAY_TIME));
        clk.write(HIGH);
    }

}

