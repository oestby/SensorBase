#include <GPIO/GPIO.hpp>
#include <Tools/tools.hpp>
#include <exceptions/io_direction_error.hpp>

using namespace gpio;

/*!
Standard constructor

*/
GPIO::GPIO(int gpio_pin, iof direction):
    gpio_pin(gpio_pin), direction(direction)
{
    this->exportPin();
}

GPIO::~GPIO() {
    this->unExportPin();
}

void GPIO::setDirection(iof new_direction) {
    direction = new_direction;
}

int GPIO::getDirection(void) const {
    return static_cast<int>(direction);
}

int GPIO::read(void) const {
    std::ifstream file;
    std::string filename, reading;
    
    filename = "/system/class/gpio/gpio" 
               + std::to_string(gpio_pin)
               + "/value";
   
    file.open(filename);
    file >> reading;
    file.close();
    
    return std::stoi(reading);
}

void GPIO::write(bool output_value) {
    if(direction != iof::OUT) {
        throw tools::IoDirectionError();
    }

    if(output_value) {
        value = 1;
    } else {
        value = 0;
    }

    std::string filename, writing;

    filename = "/system/class/gpio/gpio" 
               + std::to_string(gpio_pin) 
               + "/value";

    writing = std::to_string(value);

    std::ofstream file;
    file.open(filename);
    file << writing;
    file.close();
}

void GPIO::exportPin(void) {
    std::ofstream file;
    file.open("/system/class/gpio/export");
    file << std::to_string(gpio_pin);
    exported = true;
}

void GPIO::unExportPin(void) {
    std::ofstream file;
    file.open("/system/class/gpio/unExport");
    file << std::to_string(gpio_pin);
    exported = false;
}

bool GPIO::isExported(void) const {
    return exported;
}

