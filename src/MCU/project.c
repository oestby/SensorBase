#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/common.h>
#include <util/delay.h>

/* For ATmega328P:
 *  This code should wait for an interrupt from the master, then read the ADC
 *  and send the ADC values back to the master via SPI.
 */

#define SCK             PB5
#define SS              PB2
#define MOSI            PB3
#define MISO            PB4
#define SEND_DATA       0x1
//Temperature sensor pin
#define TSP             0

char flags = 0x0;
struct sensors {
    uint16_t temperature;
} sensor_data;

uint16_t sendMOSI(uint16_t value) {
    //If this slave is not selected, return.
    if(PORTB & _BV(SS)) {
        return 0x0;
    }
    //Create a receive buffer.
    uint16_t rx_buffer = 0x0;

    //Loop through all bits.
    int i; 
    for(i = 10; i > 0; --i) {
        //Loop until the clock is low
        while(!(PORTB & _BV(SCK)))
            ;
        //Read the master output and but in buffer.
        rx_buffer |= (MOSI << i);
        
        //Set the slave output to the i'th bit of value
        PORTB &= (((value >> i) & 0x1) << MISO);

        //Wait for clock to go high to start a new cycle.
        while(PORTB & _BV(SCK))
            ;
    }
    return rx_buffer;
}

void adcInit(void) {
    //Should set the ADC frequency divisor and
    //reference voltage as well.
    PRR &= !PRADC;
    _delay_ms(5);
}

uint16_t readADC(char adc_pin) {
    //Chose the correct ADC
    ADMUX &= (0xF & adc_pin);
    //Enable the ADC conversion
    ADCSRA |= _BV(ADEN);
    //Wait for the conversion to finish
    //There is a register to tell when the conversion is done.
    //By using that you won't have to guess.
    _delay_ms(5);

    //We have to read the low register first to still have access to the high reg.
    uint16_t value = ADCL;
    value &= ((ADCH << 8) & 0x03);

    //Turn off the ADC to save power.
    ADCSRA &= ~_BV(ADEN);
    return value;
}

ISR(INT0_vect) {
    //Disable interrupts, set flag, enable interrupts.
    cli();
    flags |= SEND_DATA;
    sei();
}

int main(void) {
    sensor_data.temperature = 0;
    //Sets the global interrupt enable
    sei();
    //Sets PB0 as an output.
    DDRB = _BV(PB0);
    //Sets the PAx ports as inputs.
    
    while(1) {
        if(flags & SEND_DATA) {
            cli();
            flags &= ~SEND_DATA;
            adcInit();
            sensor_data.temperature = readADC(TSP);
            sendMOSI(sensor_data.temperature);
            sei();
        }
    }

    return 0;
}
