#include <GPIO/GPIO.hpp>

using namespace gpio;

GPIO::GPIO(int gpio_pin, iof direction):
    gpio_pin(gpio_pin), direction(direction)
{
    this->exportPin();
    this->setValue(false);
}

GPIO::~GPIO() {
    this->deexportPin();
}

void GPIO::setDirection(iof new_direction) {
    direction = new_direction;
}

int GPIO::getDirection(void) const {
    return static_cast<int>(direction);
}

int GPIO::readValue(void) const {
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

void GPIO::setValue(bool bitValue) {
    if(bitValue) {
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

void GPIO::deexportPin(void) {
    std::ofstream file;
    file.open("/system/class/gpio/deexport");
    file << std::to_string(gpio_pin);
    exported = false;
}

bool GPIO::isExported(void) const {
    return exported;
}

