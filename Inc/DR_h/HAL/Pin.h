/*
 * Pin.h
 *
 *  Created on: Jan 2, 2021
 *      Author: ianicknoejovich
 */

#ifndef DR_H_PERIPHERALS_PIN_H_
#define DR_H_PERIPHERALS_PIN_H_

#include <System.h>

class Pin {

public:
	enum Port {PORTA, PORTB, PORTC, PORTD, PORTE};
	Pin(Port port, uint8_t pin);

protected:
	uint8_t _port;
	uint8_t _pin;

};

#endif
