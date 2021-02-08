/*
 * PWM.cpp
 *
 *  Created on: Jan 3, 2021
 *      Author: usuario
 */
#include "DR_h/HAL/PWM.h"
#include "DR_h/Hardware/DR_Timer.h"

/*!-----------INCLUDES PRIVADOS-----------------------------------------------------------------------------*/

/*!-----------DEFINES Y MACROS PRIVADOS---------------------------------------------------------------------*/

/*!-----------TIPOS DE DATOS PRIVADOS-----------------------------------------------------------------------*/

/*!-----------VARIABLES GLOBALES PRIVADAS-------------------------------------------------------------------*/
uint8_t timerInit = 0;
/*!-----------VARIABLES GLOBALES PUBLICAS-------------------------------------------------------------------*/

/*!-----------FUNCIONES-------------------------------------------------------------------------------------*/
PWM::PWM(Port port, uint8_t pin) : Pin(port, pin){

	timer_n = (Timer)getTimNum(port, pin);
	//chnl = getTimChnl()
	switch (timer_n) {
		case TIMER1:	PCLK_Enable(PCLK1, TIM1_PCLK);		break;
		case TIMER2:	PCLK_Enable(PCLK2, TIM2_PCLK);		break;
		case TIMER3:	PCLK_Enable(PCLK2, TIM3_PCLK);		break;
		case TIMER4:	PCLK_Enable(PCLK2, TIM4_PCLK);		break;
	}

	if(((timerInit >> (uint8_t)timer_n) & 0x01) == 0){
		TIM_setPLL((uint8_t)timer_n, 720);
		TIM_setCountMode((uint8_t)timer_n, UP_COUNT);
		TIM_setPeriod((uint8_t)timer_n, 100); //fPwm = 1khz. Max val = 100.
		TIM_setClockDiv((uint8_t)timer_n, CLKDIV_1);
		TIM_autoReload_en(timer_n);

		timerInit |= (1 << timer_n);
	}

	TIM_setActiveHigh((uint8_t)timer_n, chnl);
	TIM_setSel(timer_n, chnl, OUTPUT);
	TIM_setOutputMode(timer_n, chnl, PWM_MODE1);
	TIM_output_en(timer_n, chnl);

	TIM_setVal(timer_n, chnl, 0);
	TIM_preloadEn(timer_n, chnl);
}

uint8_t PWM::getTimNum(Port port, uint8_t pin){
	Timer result;

	if(port == PORTA){
		if(pin >= 8) result = TIMER1;
		else if (pin >= 6) result = TIMER3;
		else result = TIMER2;
	}
	else if(port == PORTB){
		if(pin >= 12) result = TIMER1;
		else if (pin > 6) result = TIMER4;
		else result = TIMER3;
	}


	return result;
}


/*PASOS:
 * setear el preescaler.  Divide los 72Mh por el numero del PSC. 16bits. TIM1_tick_f = 72Mhz/(PSC +1)
 * setear el modo como UP_COUNT. Va a ir de 0 a maxVAl
 * setear el periodo. Fpwm = TIM1_tick_f / (periodo - 1)
 * setear clockDivision a CLKDIV_1
 * setear polarity con setActiveHigh(channel)
 * setear chn_sel a OUTPUT}
 * setear chn_mode a PWM_MODE
 *
 * habilitar AutoReload
 * habilitar Output
 *
 * setear Val. (para 50% de duty, val = maxVal/2
 * habilitar preolad(chn)
 *
 */
