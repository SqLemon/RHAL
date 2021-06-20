//include library
#include <RHAL.h>

#define MAX_DUTY    50//from 0 to 100
#define REFRESH_TIME    50//in ms.

//Hardware declaration
HardwareTimer tim(HardwareTimer::TIMER3, 72, 100); //timer to be used for the PWM
PWM pwmPin(tim, PWM::CHANNEL_1, PORTA, 6);  //PWM pin initialization

//function that changes the pulse width for the pwm makeing it slowly turn on and off
void updateDuty(){
    //static variables to write the corresponding pulse width 
    static uint8_t val = 0, sum =1;

    if(val >= MAX_DUTY) sum = -1; //if the pulse width gets to its maximum, start substracting
    if(val <= 0) sum = 1; //if the pulse width is 0, start adding again.

    val+=sum;
    pwmPin.setDutyCycle(val);
}

int main() {
    //RHAL definition. Must be At the top
    RHAL hal;

    //Hardware inicialization
    pwmPin.init();
    SoftwareTimer changeDuty(REFRESH_TIME, &updateDuty);
    changeDuty.init();
    

    while (1) {
        hal.tick(); //system update. Must be at the top of the code     
        changeDuty.loop();
    }
}