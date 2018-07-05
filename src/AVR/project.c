#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/common.h>

/*  
 *
 *
 *
 *
 *
 */

char sendData = 0x0;
char rx_buffer = 0x0;
float temp_value = 0;

void sendMOSI(float value) {
    if(PB4) {
        return;
    }
    rx_buffer = 0x0;
    int i; 
    for(i = 8; i > 0; --i) {
        while(!PB7)
            ;
        rx_buffer |= (PB5 << i);
        float x = 1 << i;
        if(value > x) {
            PORTB &= 0xff;
        } else {
            PORTB &= 0xbf;
        }
        while(PB7)
            ;
    }
}

//void readADC(float& value) {

//}

ISR(INT0_vect) {
    sendData = 0x1;
}


int main(void) {
    //Sets the global interrupt enable
    sei();
    //Sets PB0 as an output.
    DDRB = 0x20;
    //Sets the PAx ports as inputs.
    DDRA = 0x01;
    
    while(1) {
        if(sendData) {
            sendData = 0x0;
            //readADC(&temp_value);
            sendMOSI(temp_value);
        }
    }

    return 0;
}
