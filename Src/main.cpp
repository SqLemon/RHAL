/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Damian Melamed
 * @brief          : Main program
 ******************************************************************************
 */

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

#include <DR_h/HAL/RHAL.h>

int main(void){
	RHAL hal;

	while(1){
		if(hal.one_ms_passed()){
			//TODO: everything
		}

	}

}
