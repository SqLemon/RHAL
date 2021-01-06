/*
 * SW_Timer.cpp
 *
 *  Created on: 5 ene. 2021
 *      Author: usuario
 */


/*!-----------INCLUDES PRIVADOS-----------------------------------------------------------------------------*/
#include <DR_h/HAL/SW_Timer.h>
/*!-----------DEFINES Y MACROS PRIVADOS---------------------------------------------------------------------*/

/*!-----------TIPOS DE DATOS PRIVADOS-----------------------------------------------------------------------*/

/*!-----------VARIABLES GLOBALES PRIVADAS-------------------------------------------------------------------*/

/*!-----------VARIABLES GLOBALES PUBLICAS-------------------------------------------------------------------*/

/*!-----------FUNCIONES-------------------------------------------------------------------------------------*/

SW_Timer::SW_Timer(uint16_t t , void (* f_event )(void)){
	if(!TmrFull()){
		for(uint8_t i = 0; i < N_TIMERS; i++){
			if(!TmrUsed(i)){
				_event_N = i;
				SW_Timer_Start(i, t, f_event);
			}
		}
	}
}




