//include library
#include <RHAL.h>

//Hardware declaration
OutputPin led(PORTC, 13, OutputPin::PUSH_PULL); //builtin LED


//blink function to be called every 1 millisecond

int main() {
    //RHAL definition. Must be At the top
    RHAL hal;
    Serial::init(9600);

    //Hardware inicialization
    led.init();

    while (1) {
        hal.tick(); //system update. Must be at the top of the code

        //print generic message.
        Serial::print("The LED is: ");

        //Print the led status.
        if(led()){
            Serial::println("ON!");
        }
        else{
            Serial::println("OFF");
        } 

        led = !led(); //change led status every one ms
        RHAL::delay(500);//delay half a second
    }
}