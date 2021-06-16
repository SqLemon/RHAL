//include library
#include <RHAL.h>

//Hardware declaration
OutputPin led(PORTC, 13, OutputPin::PUSH_PULL); //builtin LED
InputPin btn(PORTA, 7, InputPin::PULLUP); //btn with pullup resistor.


//blink function to be called every 1 millisecond

int main() {
    //RHAL definition. Must be At the top
    RHAL hal;

    //Hardware inicialization
    led.init();
    btn.init();


    while (1) {
        hal.tick(); //system update. Must be at the top of the code

        led = btn(); //use btn() to get the pin status.
    }
}