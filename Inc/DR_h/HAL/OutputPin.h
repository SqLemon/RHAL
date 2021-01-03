/*
 * OutputPin.h
 *
 *  Created on: Jan 2, 2021
 *      Author: ianicknoejovich
 */

#ifndef DR_H_PERIPHERALS_OUTPUTPIN_H_
#define DR_H_PERIPHERALS_OUTPUTPIN_H_

#include <System.h>
#include "Pin.h"

class OutputPin : Pin {

public:
	enum Mode {PUSH_PULL, OPEN_DRAIN};
	OutputPin(Port port, uint8_t pin, Mode mode);
	inline void set(bool v);
};

#endif /* DR_H_PERIPHERALS_OUTPUTPIN_H_ */
