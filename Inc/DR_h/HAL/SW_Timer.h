/*
 * SW_Timer.h
 *
 *  Created on: 5 ene. 2021
 *      Author: usuario
 */

#ifndef DR_H_HAL_SW_TIMER_H_
#define DR_H_HAL_SW_TIMER_H_

/*!-----------INCLUDES PUBLICOS-----------------------------------------------------------------------------*/
#include <System.h>
#include <DR_h/Hardware/DR_Software_Timer.h>
/*!-----------DEFINES Y MACROS PUBLCIAS---------------------------------------------------------------------*/

/*!-----------TIPOS DE DATOS PUBLCIAS-----------------------------------------------------------------------*/

/*!-----------VARIABLES GLOBALES PUBLICAS-------------------------------------------------------------------*/
//extern variables

/*!-----------FUNCIONES-------------------------------------------------------------------------------------*/

class SW_Timer{
public:
	SW_Timer(uint16_t t, void (* f_event )(void));
	void run();
	void setTime(uint16_t t);

private:
	uint8_t _event_N;

};

#endif /* DR_H_HAL_SW_TIMER_H_ */
