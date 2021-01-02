/*
 * Pin.cpp
 *
 *  Created on: Jan 2, 2021
 *      Author: ianicknoejovich
 */

#include <DR_h/Peripherals/Pin.h>
#include <DR_h/Hardware/DR_GPIO.h>

Pin::Pin(Port port, uint8_t pin) {
	_pin = pin;
	_port = port;
}
