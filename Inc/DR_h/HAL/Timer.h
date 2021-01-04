/*
 * PWM.h
 *
 *  Created on: Jan 3, 2021
 *      Author: ianicknoejovich
 */

#ifndef DR_H_PERIPHERALS_TIMER_H_
#define DR_H_PERIPHERALS_TIMER_H_

#include <System.h>
#include <DR_h/Hardware/DR_Timer.h>

class Timer {
public:
	enum Timers{TIM1, TIM2, TIM3, TIM4};
	Timer(Tim timerN){
		_timerN = timerN;
	};

protected:
    uint8_t _timerN;
	
};


#endif
