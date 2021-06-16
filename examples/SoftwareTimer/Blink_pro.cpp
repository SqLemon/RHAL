//include library
#include <RHAL.h>

//Hardware declaration
OutputPin led(PORTC, 13, OutputPin::PUSH_PULL); //builtin LED

//blink function to be called every 1 millisecond
void blink(){
    led = !led();
}

int main() {
    //RHAL definition. Must be At the top
    RHAL hal;
    SoftwareTimer ledTimer(1000, blink);

    //Hardware inicialization
    led.init();

    while (1) {
        hal.tick(); //system update. Must be at the top of the code
        ledTimer.loop(); //This will relaunch the timer once it ends.

    }
}