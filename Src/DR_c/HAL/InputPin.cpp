/*
 * Pin.h
 *
 *  Created on: Jan 2, 2021
 *      Author: ianicknoejovich
 */

#include <DR_h/HAL/InputPin.h>
#include <DR_h/Hardware/DR_GPIO.h>

InputPin::InputPin(Port port, uint8_t pin, Mode mode) : Pin(port, pin) {
	GPIO_setDir(_port, _pin, INPUT);
	GPIO_setInputMode(_port, _pin, mode);
}

inline bool InputPin::read() {
	return GPIO_getPin(_port, _pin);
}
