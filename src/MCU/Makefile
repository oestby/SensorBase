src=project
baud=19200
programmerDev=/dev/ttyUSB3
programmerType=dragon_isp
avrType=atmega328p
avrFreq=20000000

cflags=-g -DF_CPU=$(avrFreq) -Wall -Os -Werror 

build/$(src).o object: $(src).c
	avr-gcc $(cflags) -mmcu=$(avrType) -Wa,-ahlmns=build/$(src).lst \
	    -c -o build/$(src).o $(src).c

build/$(src).elf elf: object
	avr-gcc $(cflags) -mmcu=$(avrType) -o build/$(src).elf build/$(src).o

build/$(src).flash.hex hex: elf
	avr-objcopy -j .text -j .data -O ihex build/$(src).elf build/$(src).flash.hex

flash: hex
	avrdude -p$(avrType) -c$(programmerType) -P$(prgrammerDev) \
	    -b$(baud) -v -U flash:w:build/$(src).flash.hex
clean:
	rm build/*.hex build/*.lst build/*.elf build/*.o
