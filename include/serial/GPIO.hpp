#ifndef GPIO_HPP
#define GPIO_HPP

#include <string>
#include <fstream>

/// Namespace containing all serial communication tools.
namespace serial {
/// Contains all the GPIO related stuff.
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

        ///Sets the direction of the pin
        void setDirection(iof new_direction);
        ///Gets the direction of the pin
        int getDirection(void) const;
        ///Returns the logic value read from the pin.
        int read(void) const;
        ///Writes a logic value to the pin
        void write(bool output_value);


        ///Exports the pin so that it is active
        void exportPin(void);

        ///Un-exports the pin to deactivate it.
        void unExportPin(void);
        bool isExported(void) const;
    private:
        bool exported;
        int gpio_pin;
        iof direction;
        int value;

};
} //namespace gpio
} //namespace serial

#endif //GPIO_HPP
