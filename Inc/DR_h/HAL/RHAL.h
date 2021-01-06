/*
 * RHAL.h
 *
 *  Created on: Jan 6, 2021
 *      Author: Damián
 */

#ifndef DR_H_HAL_RHAL_H_
#define DR_H_HAL_RHAL_H_

#include <System.h>
#include <DR_h/Hardware/DR_PLL.h>
#include <DR_h/Hardware/DR_Systick.h>

class RHAL{
public:
	RHAL();
	inline uint8_t one_ms_passed(){
		uint8_t res = main_flags.Systick_ms;
		main_flags.Systick_ms = 0;
		return res;
	};

private:
	void init_CLK();
};




#endif /* DR_H_HAL_RHAL_H_ */
