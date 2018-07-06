#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/common.h>
#include <util/delay.h>

/* For ATmega328P:
 *  This code should wait for an interrupt from the master, then read the ADC
 *  and send the ADC values back to the master via SPI.
 */

#define SCK         PB5
#define SS          PB2
#define MOSI        PB3
#define MISO        PB4
#define MISO_PORT   0b00001000
#define SEND_DATA   0x1

char flags = 0x0;
char rx_buffer = 0x0;
struct sensors {
    float temperature;
} sensor_data;

void sendMOSI(float value) {
    if(SS) {
        return;
    }
    rx_buffer = 0x0;
    int i; 
    for(i = 8; i > 0; --i) {
        while(!SCK)
            ;
        rx_buffer |= (MOSI << i);
        float x = 1 << i;
        if(value > x) {
            PORTB &= MISO_PORT;
        } else {
            PORTB &= MISO_PORT;
        }
        while(SCK)
            ;
    }
}

void adcInit(void) {
    PRR &= !PRADC;
    _delay_ms(5);

}

void readADC(float* value, char adc_pin) {
    ADMUX &= (0xF & adc_pin);
    ADCSRA |= ADEN;
    _delay_ms(5);

    char LOW = ADCL;
    char HIGH = ADCH;

    *value = (HIGH << 8) | LOW;
}

ISR(INT0_vect) {
    flags |= SEND_DATA;
}


int main(void) {
    sensor_data.temperature = 0;
    //Sets the global interrupt enable
    sei();
    //Sets PB0 as an output.
    DDRB = 0b00001000;
    //Sets the PAx ports as inputs.
    
    while(1) {
        if(flags & SEND_DATA) {
            cli();
            flags &= !SEND_DATA;
            adcInit();
            readADC(&sensor_data.temperature, 0);
            sendMOSI(sensor_data.temperature);
            sei();
        }
    }

    return 0;
}
