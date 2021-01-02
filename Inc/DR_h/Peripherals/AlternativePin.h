/*
 * AlternativePin.h
 *
 *  Created on: Jan 2, 2021
 *      Author: ianicknoejovich
 */

#ifndef DR_H_PERIPHERALS_ALTERNATIVEPIN_H_
#define DR_H_PERIPHERALS_ALTERNATIVEPIN_H_

#include <System.h>
#include "Pin.h"

class AlternativePin : Pin {

public:
	enum Mode {PUSHPULL, OPENDRAIN};
	AlternativePin(Port port, uint8_t pin, Mode mode);

};

#endif /* DR_H_PERIPHERALS_ALTERNATIVEPIN_H_ */
