/*
 * InputPin.h
 *
 *  Created on: Jan 2, 2021
 *      Author: ianicknoejovich
 */

#ifndef DR_H_PERIPHERALS_INPUTPIN_H_
#define DR_H_PERIPHERALS_INPUTPIN_H_

#include <System.h>
#include "Pin.h"

class InputPin : Pin {

public:
	enum Mode {PULLUP, PULLDOWN, FLOATING, ANALOG};
	InputPin(Port port, uint8_t pin, Mode mode);
	inline bool read();
};

#endif /* DR_H_PERIPHERALS_INPUTPIN_H_ */