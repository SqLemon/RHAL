/*
 * Pin.h
 *
 *  Created on: Jan 2, 2021
 *      Author: ianicknoejovich
 */

#include <DR_h/HAL/AlternativePin.h>
#include <DR_h/Hardware/DR_GPIO.h>

AlternativePin::AlternativePin(Port port, uint8_t pin, Mode mode) : Pin(port, pin) {
	// GPIO_setDir(_port, _pin, OUTPUT);	// TODO Cuál va?
	GPIO_setAltMode(_port, _pin, mode);
}
