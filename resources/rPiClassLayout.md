# The layout of the GIPO pins in the Raspberry Pi 
<pre>
/sys/class/gpio/
           | -- export                 //This is used to start a pin.
           | -- unexport               //This is used to stop a pin.
           | -- gpio1/                 //These are unique to each pin.
           | -- gpio2/
           |    ...
           \ -- gpio*/
                | -- direction         //The direction of the pin.
                \ -- value             //The value of the pin.
</pre>
                        
## How to work with the RPi GPIO:

To read a pin it first needs to be exported:

    $ #Prepare reading for whatever PIN_NUMBER is set to.
    $ echo "$(PIN_NUMBER)" > /sys/class/gpio/export

Then we need to set a direction 'in' or 'out':

    $ echo "in" > /sys/class/gpio/gpio$(PIN_NUMBER)/direction

From here we can access the values of the pin, by reading or writing to the
corresponding value file:

    $ echo "1" > /sys/class/gpio/gpio4/value
    $ #Or reading
    $ cat /sys/class/gpio/gpio12/value

And to finish it all up we need to unexport the pin:

    $ echo "$(PIN_NUMBER)" > /sys/class/gpio/unexport

