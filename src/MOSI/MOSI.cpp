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
    //Under the assumption that the slave is active low.
    ss.write(HIGH);
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

void MOSIClas::initSlave(void) {
    using std::chrono::microseconds;
    ss.write(LOW);
    std::this_thread::sleep_for(microseconds(SPI_SLAVE_READY_DELAY));
}

char MOSIClass::writeData(char msg) {
    //As I am most likely working with an 8 bit AVR
    //this should be a good representation of the bits.
    std::array<int, 8> bits;
    std::array<int, 8> rx_buffer;

    //The delay required by the AVR betwen each bit transfer.
    auto delay = std::chrono::microseconds(SPI_DELAY_TIME);

    //Extract the bits from the byte msg.
    bits = extractBits(msg);

    //Go through all the bits, writing and reading for each time with the delay.
    for(int i = 0; i < 8; ++i) {
        clk.write(LOW);
        rx_buffer[i] = in.read();
        out.write(bits[i]);
        std::this_thread::sleep_for(delay);
        clk.write(HIGH);
    }

    char data = parseBits(rx_buffer);
    return data;
}

