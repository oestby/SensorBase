#include <GPIO/GPIO.hpp>
#include <gtest/gtest.h>

using namespace gpio;

class GPIOTest: public ::testing::Test {
    public:
        GPIOTest():
            gpio_1(14, iof::OUT), gpio_2(15, iof::IN) { }
        /*        
        virtual void SetUp() {
            gpio_1 = GPIO(14, iof::OUT);
            gpio_2 = GPIO(15, iof::OUT);
        }
        */
    protected: 
        GPIO gpio_1, gpio_2;
};

TEST_F(GPIOTest, test_export) {
    ASSERT_TRUE(gpio_1.isExported());
    ASSERT_TRUE(gpio_2.isExported());
    
    gpio_1.unExportPin();
    gpio_2.unExportPin();

    ASSERT_FALSE(gpio_1.isExported());
    ASSERT_FALSE(gpio_2.isExported());
}

int main(int argc, char** argv) {
    /* 
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
    */
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();


}

