/*
 * DR_PLL.c
 *
 *  Created on: Dec 30, 2020
 *  Author: Damian Melamed
 */


/*!-----------INCLUDES PRIVADOS-----------------------------------------------------------------------------*/
#include <DR_h/Hardware/DR_PLL.h>

#ifdef __cplusplus
extern "C" {
#endif

/*!-----------DEFINES Y MACROS PRIVADOS---------------------------------------------------------------------*/
#define RCC_BASE            (AHB_PERIPH_BASE + 0x00001000UL)
#define RCC                	((RCC_t *)RCC_BASE)

#define FLASH_BASE			(AHBPERIPH_BASE + 0x00002000UL)
#define FLASH_ACR			(*(uint32_t *) FLASH_BASE)

#define AHB_SRAM_EN		2
#define AHB_FLITF_EN	4
#define AHB_FSMC_EN		8
#define AHB_SDIO_EN		10

/*!-----------TIPOS DE DATOS PRIVADOS-----------------------------------------------------------------------*/
typedef struct{
	uint32_t HSI_on:	1;
	uint32_t HSI_ready: 1;
	uint32_t RESERVED0: 1;
	uint32_t HSI_trim:  5;
	uint32_t ISI_calib: 8;
	uint32_t HSE_on:	1;
	uint32_t HSE_ready:	1;
	uint32_t HSE_bypass:1;
	uint32_t CSS_on:	1;
	uint32_t RESERVED1:	4;
	uint32_t PLL_on:	1;
	uint32_t PLL_ready:	1;
	uint32_t RESERVED2:	6;
} RCC_CR_t;


typedef struct{
	uint32_t SysClk_sw:		2; //SW. system clock switch
	uint32_t SysClk_sw_stat:2; //SWS system clock switch status
	uint32_t AHB_presc:		4; //HPRE. AHB preescaler
	uint32_t APB1_presc:	3; //PPRE1. APB1 low-speed preescaler
	uint32_t APB2_presc:	3; //PPRE2. APB2 high-speed preescaler
	uint32_t ADC_presc:		2; //ADCPRE. adc preescaler
	uint32_t PLL_src:		1; //PLLSRC. PLL source
	uint32_t HSE_PLL_prediv:	1; //PLLXTPRE. HSE dividier for
	uint32_t PLL_mult:		4; //PLLMUL. PLL multiplication factor
	uint32_t USB_presc:		1; //USBPRE. USB prescaler
	uint32_t RESERVED0:		1;
	uint32_t Clk_output:	3; //MCO. microcontroller clock output
	uint32_t RESERVED1:		5;
}RCC_CFGR_t;

typedef struct{
  __RW RCC_CR_t 	CR;
  __RW RCC_CFGR_t 	CFGR;
  __RW uint32_t 	CIR;
  __RW uint32_t 	APB2_RST;
  __RW uint32_t 	APB1_RST;
  __RW uint32_t 	AHB_EN;
  __RW uint32_t 	APB2_EN;
  __RW uint32_t 	APB1_EN;
  __RW uint32_t 	BDCR;
  __RW uint32_t 	CSR;

} RCC_t;
/*!-----------VARIABLES GLOBALES PRIVADAS-------------------------------------------------------------------*/

/*!-----------VARIABLES GLOBALES PUBLICAS-------------------------------------------------------------------*/

/*!-----------FUNCIONES-------------------------------------------------------------------------------------*/

/** @brief Iniciializa y configura la entrada de clock, el PLL y los clocks de los perifericos
 *
 */

enum AHB_divFactor{AHB_DIV_NONE, AHB_DIV_2 = 8, AHB_DIV_4, AHB_DIV_8, AHB_DIV_16, AHB_DIV_64, AHB_DIV_128, AHB_DIV_256, AHB_DIV_512};
enum APB_divFactor{APB_DIV_NONE, APB_DIV_2 = 4, APB_DIV_4, APB_DIV_8, APB_DIV_16};
enum ADC_divFactor{ADC_DIV_2, ADC_DIV_4, ADC_DIV_6, ADC_DIV_8};
enum USB_divFactor{USB_DIV_1_5, USB_DIV_NONE};
enum FLASH_latencyWS{FLASH_LATENCY_24MHZ = 0, FLASH_LATENCY_48MHZ = 2, FLASH_LATENCY_72MHZ = 4};
enum SYSCLK_src{SYSCLK_HSI, SYSCLK_HSE, SYSCLK_PLL};
enum PLL_src{PLL_SRC_HSI,PLL_SRC_HSE};
enum PLL_prediv{HSE_PREDIV_NONE, HSE_PREDIV_2};
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

void CLK_init(){
	//Initialize system by using external clock
	RCC->CR.HSE_on = 1;			//"Turn On" external clock
	while(!RCC->CR.HSE_ready);	//Wait until external clock is stable

	//configure periferials preescalers
	RCC->CFGR.AHB_presc = AHB_DIV_NONE; //72MHz
	RCC->CFGR.APB1_presc = APB_DIV_2; //APB1. 36Mhz
	RCC->CFGR.APB2_presc = APB_DIV_NONE; //APB2. 72MHz
	RCC->CFGR.ADC_presc = ADC_DIV_6; //ADC. 12Mhz
	RCC->CFGR.USB_presc = USB_DIV_1_5; //

	FLASH_ACR |= FLASH_LATENCY_72MHZ; //set 2 wait states for speeds > to 48MHz.

	//configure PLL
	RCC->CFGR.PLL_mult = PLL_MULT_9; //PLL mult = x9
	RCC->CFGR.PLL_src = PLL_SRC_HSE; //HSE as PLL source
	RCC->CFGR.HSE_PLL_prediv = HSE_PREDIV_NONE; //PLL input = HSE. (si se pone '1' -> PLL input = HSE/2)

	//enable PLL
	RCC->CR.PLL_on = 1;
	while(!RCC->CR.PLL_ready);


	RCC->CFGR.SysClk_sw = SYSCLK_PLL; //PLL as system clk source
	while(RCC->CFGR.SysClk_sw_stat != SYSCLK_PLL);
}



/** @brief 	Permite hablitar los clocks de los perifericos
 *  @param 	registro a escribir. USAR DEFINES APB1 y APB2
 *  @param  bit a escribir
 *  @param 	habilitacion. 1 para habilitar, 0 para deshabilitar
 */
void PCLK_setEnable(uint8_t reg, uint8_t bit, uint8_t en){
	if(reg > PCLK2) return;
	if(bit > 31) return;

	if(en)
		RCC->APB1_EN |= (1 << bit);
	else
		RCC->APB1_EN &= ~(1 << bit);
}

#ifdef __cplusplus
}
#endif

