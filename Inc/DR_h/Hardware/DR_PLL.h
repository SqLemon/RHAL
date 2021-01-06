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






enum APB_divFactor{APB_DIV_NONE, APB_DIV_2 = 4, APB_DIV_4, APB_DIV_8, APB_DIV_16};
enum ADC_divFactor{ADC_DIV_2, ADC_DIV_4, ADC_DIV_6, ADC_DIV_8};
enum USB_divFactor{USB_DIV_1_5, USB_DIV_NONE};
enum AHB_divFactor{AHB_DIV_NONE,
	AHB_DIV_2 = 8,
	AHB_DIV_4,
	AHB_DIV_8,
	AHB_DIV_16,
	AHB_DIV_64,
	AHB_DIV_128,
	AHB_DIV_256,
	AHB_DIV_512
};

enum FLASH_latencyWS{FLASH_LATENCY_24MHZ = 0, FLASH_LATENCY_48MHZ = 2, FLASH_LATENCY_72MHZ = 4};
enum SYSCLK_src{SYSCLK_HSI, SYSCLK_HSE, SYSCLK_PLL};

enum PLL_src{PLL_SRC_HSI,PLL_SRC_HSE};
enum PLL_multFactor{
	PLL_MULT_2,
	PLL_MULT_3,
	PLL_MULT_4,
	PLL_MULT_5,
	PLL_MULT_6,
	PLL_MULT_7,
	PLL_MULT_8,
	PLL_MULT_9,
	PLL_MULT_10,
	PLL_MULT_11,
	PLL_MULT_12,
	PLL_MULT_13,
	PLL_MULT_14,
	PLL_MULT_15,
};
/*!-----------TIPOS DE DATOS PUBLCIAS-----------------------------------------------------------------------*/

/*!-----------VARIABLES GLOBALES PUBLICAS-------------------------------------------------------------------*/
//extern variables

/*!-----------FUNCIONES-------------------------------------------------------------------------------------*/
inline void CLK_enableHSE(void);
inline void CLK_setPrescaler(uint8_t AHB, uint8_t APB1, uint8_t APB2, uint8_t ADC, uint8_t USB);
inline void CLK_FLASH_setLatency(uint8_t waitSatate);
inline void CLK_setPLL_mult(uint8_t mult);
inline void CLK_setPLL_src(uint8_t src);
inline void CLK_PLL_HSEprediv(uint8_t e);
inline void CLK_enablePLL();
inline void CLK_setSystemCLK(uint8_t src);

void PCLK_setEnable(uint8_t reg, uint8_t bit, uint8_t en);

#ifdef __cplusplus
}
#endif

#endif /* DR_H_DR_PLL_H_ */
