//include library
#include <RHAL.h>

//Hardware declaration
OutputPin led(PORTC, 13, OutputPin::PUSH_PULL); //builtin LED


int main() {
    //RHAL definition. Must be At the top
    RHAL hal;

    //Hardware inicialization
    led.init();

    while (1) {
        hal.tick(); //system update. Must be at the top of the code
        
        led = 0;
        RHAL::delay(1000); //delay 1 second
        led = 1;
        RHAL::delay(1000); //delay 1 second
    }
}