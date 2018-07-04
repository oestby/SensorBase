#ifndef GPIO_HPP
#define GPIO_HPP

#include <string>
#include <fstream>

namespace gpio {

//Input or output flags.
enum class iof { 
    IN, 
    OUT 
};

constexpr int LOW   = 0;
constexpr int HIGH  = 1;

class GPIO {
    public:
        /// Exports the chosen GPIO pin and sets the direction
        GPIO(int gpio_pin, iof direction = iof::IN);
        /// Deexports the GPIO pin.
        ~GPIO();

        void setDirection(iof new_direction);
        int getDirection(void) const;
        int readValue(void) const;
        void setValue(bool bitValue);

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
