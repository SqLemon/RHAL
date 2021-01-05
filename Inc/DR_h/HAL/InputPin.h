/*
 * InputPin.h
 *
 *  Created on: Jan 2, 2021
 *      Author: ianicknoejovich
 */

#ifndef DR_H_HAL_INPUTPIN_H_
#define DR_H_HAL_INPUTPIN_H_

#include <System.h>
#include "Pin.h"
#include "OutputPin.h"

class InputPin : Pin {

public:
	enum Mode {PULLUP, PULLDOWN, FLOATING, ANALOG};
	InputPin(Port port, uint8_t pin, Mode mode = Mode::PULLDOWN);
	inline bool read();
	inline bool operator()();
//	OutputPin toOutputPin(OutputPin::Mode mode);
};

#endif /* DR_H_HAL_INPUTPIN_H_ */
