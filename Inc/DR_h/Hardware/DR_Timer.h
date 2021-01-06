/*
 * DR_Timer1.h
 *
 *  Created on: 3 ene. 2021
 *      Author: usuario
 */

#ifndef DR_H_HARDWARE_DR_TIMER_H_
#define DR_H_HARDWARE_DR_TIMER_H_

/*!-----------INCLUDES PUBLICOS-----------------------------------------------------------------------------*/
#include <System.h>

/*!-----------DEFINES Y MACROS PUBLCIAS---------------------------------------------------------------------*/
enum count_mode{UP_COUNT, DOWN_COUNT};
enum ClockDiv_val{CLKDIV_1, CLKDIV_2, CLKDIV_4};
enum mode_chn{CHN1_MODE, CHN2_MODE, CHN3_MODE, CHN4_MODE,};
enum chn_sel{ OUTPUT, INPUT_TI2, INPUT_TI1, INPUT_TRC}; 
enum encoder_mode{ENC_MODE1 = 1, ENC_MODE2, ENC_MODE3};
enum PWM_mode{PWM_MODE1=6, PWM_MODE2};

/*!-----------TIPOS DE DATOS PUBLCIAS-----------------------------------------------------------------------*/

/*!-----------VARIABLES GLOBALES PUBLICAS-------------------------------------------------------------------*/
//extern variables

/*!-----------FUNCIONES-------------------------------------------------------------------------------------*/
extern inline void TIM_setPeriod(uint8_t timN, uint16_t val);
extern inline void TIM_setCountMode(uint8_t timN, uint8_t mode);
extern inline void TIM_autoReload_en(uint8_t timN);
extern inline void TIM_counter_en(uint8_t timN);
extern inline void TIM_setPLL(uint8_t timN, uint16_t val);
extern inline void TIM_setClockDiv(uint8_t timN, uint8_t val);
extern inline void TIM_setActiveHigh(uint8_t timN, uint8_t chnl);
extern inline void TIM_output_en(uint8_t timN, uint8_t chnl);
extern inline void TIM_setVal(uint8_t timN, uint8_t chnl, uint16_t val);
extern inline void TIM_setSlaveMode(uint8_t timN, uint8_t val);
extern inline void TIM_setInput_NInv(uint8_t timN, uint8_t chnl);
extern inline uint16_t TIM_getCount(uint8_t timN, uint8_t chnl);

void TIM1_setSel(uint8_t timN, uint8_t chn, uint8_t sel);
void TIM1_setOutputMode(uint8_t timN, uint8_t chn, uint8_t mode);
void TIM1_setInputPLL(uint8_t timN, uint8_t chn, uint8_t pll);
void TIM1_preloadEn(uint8_t timN, uint8_t chn);


#endif /* DR_H_HARDWARE_DR_TIMER1_H_ */
