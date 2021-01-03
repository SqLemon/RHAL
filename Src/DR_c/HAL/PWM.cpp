/*
 * PWM.cpp
 *
 *  Created on: Jan 3, 2021
 *      Author: usuario
 */


/*!-----------INCLUDES PRIVADOS-----------------------------------------------------------------------------*/

/*!-----------DEFINES Y MACROS PRIVADOS---------------------------------------------------------------------*/

/*!-----------TIPOS DE DATOS PRIVADOS-----------------------------------------------------------------------*/

/*!-----------VARIABLES GLOBALES PRIVADAS-------------------------------------------------------------------*/

/*!-----------VARIABLES GLOBALES PUBLICAS-------------------------------------------------------------------*/

/*!-----------FUNCIONES-------------------------------------------------------------------------------------*/



/*PASOS:
 * setear el preescaler.  Divide los 72Mh por el numero del PSC. 16bits
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
