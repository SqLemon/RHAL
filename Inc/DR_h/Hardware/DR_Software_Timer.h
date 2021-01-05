/*
 * DR_Software_Timer.h
 *
 *  Created on: 5 ene. 2021
 *      Author: usuario
 */

#ifndef DR_H_HARDWARE_DR_SOFTWARE_TIMER_H_
#define DR_H_HARDWARE_DR_SOFTWARE_TIMER_H_

/*!-----------INCLUDES PUBLICOS-----------------------------------------------------------------------------*/
#include <System.h>
/*!-----------DEFINES Y MACROS PUBLCIAS---------------------------------------------------------------------*/
#define N_TIMERS 32
/*!-----------TIPOS DE DATOS PUBLCIAS-----------------------------------------------------------------------*/

/*!-----------VARIABLES GLOBALES PUBLICAS-------------------------------------------------------------------*/

/*!-----------FUNCIONES-------------------------------------------------------------------------------------*/
uint8_t SW_Timer_Start (uint8_t event_n , uint16_t t , void (* f_event )(void));
uint8_t SW_Timer_Pause ( uint8_t event_n , uint8_t modo);
uint8_t SW_Timer_Stop ( uint8_t event_n);
void SW_Timer_Run(uint8_t event_n);
inline uint8_t TmrUsed(uint8_t b);
inline uint8_t TmrFull();

uint8_t SW_Timer_Set ( uint8_t event_n , uint32_t t );
int16_t SW_Timer_Get ( uint8_t event_n);

void SW_Timer_Close ( void );
void SW_Timer_Discount ( void );

#endif /* DR_H_HARDWARE_DR_SOFTWARE_TIMER_H_ */
