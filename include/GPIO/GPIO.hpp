#ifndef GPIO_HPP
#define GPIO_HPP

#include <string>
#include <fstream>

namespace gpio {

///Input or output flags for usage in the GPIO class.
enum class iof { 
    IN, 
    OUT 
};

///Encoding of logic values.
constexpr int LOW  = 0;
constexpr int HIGH = 1;

/*!
This is a class for controlling the Raspberry Pi's GPIO pins.

Important notes on the usage is that an input pin can not change the value of its associated pin. That will throw and exception.
*/
class GPIO {
    public:
        /// Exports the chosen GPIO pin and sets the direction
        GPIO(int gpio_pin, iof direction = iof::IN);
        /// Deexports the GPIO pin.
        ~GPIO();

        void setDirection(iof new_direction);
        int getDirection(void) const;
        int read(void) const;
        void write(bool output_value);

        void exportPin(void);
        void unExportPin(void);
        bool isExported(void) const;
    private:
        bool exported;
        int gpio_pin;
        iof direction;
        int value;

};
} //namespace gpio

#endif //GPIO_HPP
