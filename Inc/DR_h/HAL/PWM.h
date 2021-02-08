/*
 * PWM.h
 *
 *  Created on: Jan 3, 2021
 *      Author: ianicknoejovich
 */

#ifndef DR_H_PERIPHERALS_PWM_H_
#define DR_H_PERIPHERALS_PWM_H_

#include <System.h>
#include "Pin.h"

class PWM : Pin{
public:
	PWM(Port port, uint8_t pin);
	enum Timer{TIMER1, TIMER2, TIMER3, TIMER4};

	static uint8_t getTimNum(Port port, uint8_t pin);

	//TODO

private:
	static uint8_t timerInit;
	Timer timer_n;
	uint8_t chnl;


};

#endif
