#include <GPIO/GPIO.hpp>
#include <iostream>

using namespace gpio;

int main() {
    GPIO pin_1(1, iof::OUT);
    GPIO pin_2(2, iof::IN);

    std::cout << "Is pin 1 exported? " << pin_1.isExported() << std::endl;
    std::cout << "Is pin 2 exported? " << pin_2.isExported() << std::endl;

    std::cout << "Value of pin 1: ";
    std::cout << pin_1.readValue() << std::endl;
    std::cout << "Value of pin 2: ";
    std::cout << pin_2.readValue() << std::endl;

    std::cout << "Setting new values" << std::endl;
    pin_1.setValue(true);
    pin_2.setValue(true);

    std::cout << "Value of pin 1: ";
    std::cout << pin_1.readValue() << std::endl;
    std::cout << "Value of pin 2: ";
    std::cout << pin_2.readValue() << std::endl;

    std::cout << "Deexporting pins..." << std::endl;
    pin_1.deexportPin();
    pin_2.deexportPin();

    std::cout << "Is pin 1 exported? " << pin_1.isExported() << std::endl;
    std::cout << "Is pin 2 exported? " << pin_2.isExported() << std::endl;

}


