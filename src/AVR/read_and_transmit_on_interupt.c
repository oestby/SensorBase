#include <avr/io.h>

/*  
 *
 *
 *
 *
 *
 */

void sendMOSI(float value) {
    

}

void handeInterrupt() {
    _CLI(); //Interrupts within interrupts are no good.

    _SEI();
}

ISR(

int main(void) {
    //Sets the global interrupt enable
    _SEI();
    //Sets PB0 as an output.
    DDRB = 0x01;
    //Sets the PAx ports as inputs.
    DDRA = 0x01;
    //Sets PB0 high.
    PORTB = 0x01;

    
    //Makes the microcontroller sleep.
    _SLEEP();


    return 0;
}
