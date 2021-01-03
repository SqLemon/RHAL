/*
 * Pin.h
 *
 *  Created on: Jan 2, 2021
 *      Author: ianicknoejovich
 */

#include <DR_h/HAL/OutputPin.h>
#include <DR_h/Hardware/DR_GPIO.h>

OutputPin::OutputPin(Port port, uint8_t pin, Mode mode) : Pin(port, pin) {
	GPIO_setDir(_port, _pin, OUTPUT);
	GPIO_setOutputMode(_port, _pin, mode);
}

inline void OutputPin::set(bool v) {
	GPIO_setPin(_port, _pin, v);
}
