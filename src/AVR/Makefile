src=project
baud=19200
programmerDev=/dev/ttyUSB3
programmerType=""
avrType=atmega8535
avrFreq=1000000

cflags=-g -DF_CPU=$(avrFreq) -Wall -Os -Werror -Wextra

$(src).o object:
	avr-gcc $(cflags) -mmcu=$(avrType) -Wa,-ahlmns=$(src).lst \
	    -c -o $(src).o $(src).c

$(src).elf elf: object
	avr-gcc $(cflags) -mmcu=$(avrType) -o $(src).elf $(src).o

$(src).flash.hex hex: elf
	avr-objcopy -j .text -j .data -O ihex $(src).elf $(src).flash.hex

flash: hex
	avrdude -p$(avrType) -c$(programmerType) -P$(prgrammerDev) \
	    -b$(baud) -v -U flash:w:$(src).flash.hex
clean:
	rm *.hex *.lst *.elf *.o
