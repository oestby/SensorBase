#include <avr/io.h>
#include <avr/interrupt.h>

uint8_t intFlag = 0;

ISR(INT0_vect) {
   intFlag = 1; 
}

int main(void) {
    sei();

    while(1) {
        if(intFlag) {
            intFlag = 0;
            PORTB ^= 0xff;
        }
    }
}

