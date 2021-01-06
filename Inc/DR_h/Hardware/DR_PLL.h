/*
 * DR_PLL.h
 *
 *  Created on: Dec 30, 2020
 *  Author: Damian Melamed
 */

#ifndef DR_H_DR_PLL_H_
#define DR_H_DR_PLL_H_

/*!-----------INCLUDES PUBLICOS-----------------------------------------------------------------------------*/
#include <System.h>

#ifdef __cplusplus
extern "C" {
#endif

/*!-----------DEFINES Y MACROS PUBLCIAS---------------------------------------------------------------------*/
enum{PCLK1, PCLK2};
enum PCLK2_bits{
	AFIO_PCLK = 0,
	IOPA_PCLK = 1,
	IOPB_PCLK = 2,
	IOPC_PCLK = 3,

	ADC1_PCLK = 9,
	ADC2_PCLK = 10,
	TIM1_PCLK = 11,
	SPI1_PCLK = 12,

	USART1_PCLK = 14,
};

enum PCLK1_bits{
	TIM2_PCLK = 0,
	TIM3_PCLK = 1,
	TIM4_PCLK = 2,

	WWDG_PCLK = 11,

	SPI2_PCLK = 14,

	USART2_PCLK = 17,
	USART3_PCLK = 18,

	I2C1_PCLK = 21,
	I2C2_PCLK = 22,
	USB_PCLK = 23,

	CAN_PCLK = 25,

	BKP_PCLK = 27,
	PWR_PCLK = 28,
	DAC_PCLK = 29
};

/*!-----------TIPOS DE DATOS PUBLCIAS-----------------------------------------------------------------------*/

/*!-----------VARIABLES GLOBALES PUBLICAS-------------------------------------------------------------------*/
//extern variables

/*!-----------FUNCIONES-------------------------------------------------------------------------------------*/
void CLK_init();
void PCLK_setEnable(uint8_t reg, uint8_t bit, uint8_t en);

#ifdef __cplusplus
}
#endif

#endif /* DR_H_DR_PLL_H_ */
