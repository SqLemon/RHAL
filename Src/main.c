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

#include <DR_h/Hardware/DR_GPIO.h>
#include <DR_h/Hardware/DR_PLL.h>
#include <DR_h/Hardware/DR_Systick.h>

volatile Flags_t main_flags;//variable global para flags

int main(void)
{
	CLK_init();
	Systick_init();

	main_flags.Systick_ms = 0;

	while(1){
		if(main_flags.Systick_ms){
			//huboo una iterrupción de 1ms
			main_flags.Systick_ms = 0;

			//TODO: everything
		}

	}

}
