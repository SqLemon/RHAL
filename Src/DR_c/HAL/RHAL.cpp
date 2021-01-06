/*
 * RHAL.cpp
 *
 *  Created on: Jan 6, 2021
 *      Author: Damián
 */
#include <DR_h/HAL/RHAL.h>

volatile Flags_t main_flags;//variable global para flags

RHAL::RHAL(){
	init_CLK();
	Systick_init();
	main_flags.Systick_ms = 0;
}

void RHAL::init_CLK(){
	//configure clock
	CLK_enableHSE();
	CLK_setPrescaler(AHB_DIV_NONE,
			APB_DIV_2,
			APB_DIV_NONE,
			ADC_DIV_6,
			USB_DIV_1_5);

	CLK_FLASH_setLatency(FLASH_LATENCY_72MHZ);

	CLK_setPLL_mult(PLL_MULT_9);
	CLK_setPLL_src(PLL_SRC_HSE);
	CLK_PLL_HSEprediv(false);

	CLK_enablePLL();
	CLK_setSystemCLK(SYSCLK_PLL);
}
