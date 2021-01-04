/*
 * OutputPin.h
 *
 *  Created on: Jan 2, 2021
 *      Author: ianicknoejovich
 */

#ifndef DR_H_HAL_OUTPUTPIN_H_
#define DR_H_HAL_OUTPUTPIN_H_

#include <System.h>
#include "Pin.h"
//#include "InputPin.h"

class OutputPin : Pin {

public:
	enum Mode {PUSH_PULL, OPEN_DRAIN};
	OutputPin(Port port, uint8_t pin, Mode mode);
	inline void set(bool v);
	inline void operator=(bool v);
//	InputPin toInputPin(InputPin::Mode mode);

};

#endif /* DR_H_HAL_OUTPUTPIN_H_ */
