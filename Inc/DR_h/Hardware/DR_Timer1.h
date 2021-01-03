/*
 * DR_Timer1.h
 *
 *  Created on: 3 ene. 2021
 *      Author: usuario
 */

#ifndef DR_H_HARDWARE_DR_TIMER1_H_
#define DR_H_HARDWARE_DR_TIMER1_H_

/*!-----------INCLUDES PUBLICOS-----------------------------------------------------------------------------*/
#include <System.h>
/*!-----------DEFINES Y MACROS PUBLCIAS---------------------------------------------------------------------*/
enum count_mode{UP_COUNT, DOWN_COUNT};
enum ClockDiv_val{CLKDIV_1, CLKDIV_2, CLKDIV_4};
enum mode_chn{CHN1_MODE, CHN2_MODE, CHN3_MODE, CHN4_MODE,};
enum chn_sel{ OUTPUT, INPUT_TI2, INPUT_TI1, INPUT_TRC};

#define PWM_MODE	7
/*!-----------TIPOS DE DATOS PUBLCIAS-----------------------------------------------------------------------*/

/*!-----------VARIABLES GLOBALES PUBLICAS-------------------------------------------------------------------*/
//extern variables

/*!-----------FUNCIONES-------------------------------------------------------------------------------------*/


#endif /* DR_H_HARDWARE_DR_TIMER1_H_ */
