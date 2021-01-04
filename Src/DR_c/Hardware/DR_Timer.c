/*
 * DR_Timer1.c
 *
 *  Created on: 3 ene. 2021
 *      Author: usuario
 */

/*!-----------INCLUDES PRIVADOS-----------------------------------------------------------------------------*/
#include <DR_h/Hardware/DR_Timer.h>
#include <System.h>

#ifdef __cplusplus
extern "C" {
#endif

/*!-----------DEFINES Y MACROS PRIVADOS---------------------------------------------------------------------*/
#define TIM1_BASE             (APB2_PERIPH_BASE + 0x00002C00UL)
#define TIM2_BASE             (APB1_PERIPH_BASE + 0x00000000UL)
#define TIM3_BASE             (APB1_PERIPH_BASE + 0x00000400UL)
#define TIM4_BASE             (APB1_PERIPH_BASE + 0x00000800UL)

#define CCER_OUT_EN_BIT	0
#define CCER_POLAR_BIT	1

//#define 	TIM1_UpdateInt_en()			(TIM_REG[timN]->DIER.Update_intEn = 1)
//#define	TIM1_CompareInt_en()		(TIM_REG[timN]->DIER.COM_intEn = 1)
//#define 	TIM1_CompareChn_int_en(c)	(TIM_REG[timN]->DIER.CC_intEN |= (1 << c))
/*!-----------TIPOS DE DATOS PRIVADOS-----------------------------------------------------------------------*/
typedef struct{
	uint32_t Counter_en: 1;
	uint32_t UDIS: 1;
	uint32_t URS: 1;
	uint32_t OPM:1;
	uint32_t Direction: 1;
	uint32_t Center_align: 2;
	uint32_t AR_en: 1;
	uint32_t Clock_div:  2;
	uint32_t RESERVED: 22;
}TIM_CR1_t;

typedef struct{
	uint32_t Update_intEn: 1;
	uint32_t CC_intEn: 4;
	uint32_t COM_intEn: 4;
	uint32_t Trig_intEn: 1;
	uint32_t Break_intEn: 1;
	uint32_t Update_DMA_intEn: 1;
	uint32_t CC1_DMA_intEn: 1;
	uint32_t CC2_DMA_intEn: 1;
	uint32_t CC3_DMA_intEn: 1;
	uint32_t CC4_DMA_intEn: 1;
	uint32_t COM_DMA_intEn: 1;
	uint32_t Trig_DMA__intEn: 1;
	uint32_t RESERVED: 17;
}TIM_DIER_t;

typedef struct{
	uint32_t chnA_sel: 2;
	uint32_t chnA_Fast_En: 1;
	uint32_t chnA_preLd_en: 1;
	uint32_t chnA_mode: 3;
	uint32_t chnA_clr_en: 1;
	uint32_t chnB_sel: 2;
	uint32_t chnB_Fast_En: 1;
	uint32_t chnB_preLd_en: 1;
	uint32_t chnB_mode: 3;
	uint32_t chnB_clr_en: 1;
	uint32_t RESERVED: 16;
}TIM_CCMR_OUT_t;

typedef struct{
	uint32_t chnA_sel: 2;
	uint32_t chnA_Input_PLL: 2;
	uint32_t chnA_filter_sel: 4;
	uint32_t chnB_sel: 2;
	uint32_t chnB_Input_PLL: 2;
	uint32_t chnB_filter_sel: 4;
	uint32_t RESERVED: 16;
}TIM_CCMR_IN_t;

typedef struct{
  __RW TIM_CR1_t CR1;            /*!< TIM control register 1,                      Address offset: 0x00 */
  __RW uint32_t CR2;             /*!< TIM control register 2,                      Address offset: 0x04 */
  __RW uint32_t SMCR;            /*!< TIM slave Mode Control register,             Address offset: 0x08 */
  __RW TIM_DIER_t DIER;          /*!< TIM DMA/interrupt enable register,           Address offset: 0x0C */
  __RW uint32_t SR;              /*!< TIM status register,                         Address offset: 0x10 */
  __RW uint32_t EGR;             /*!< TIM event generation register,               Address offset: 0x14 */
  union{
	  __RW TIM_CCMR_OUT_t CCMR1_OUT;   /*!< TIM  capture/compare mode register 1,        Address offset: 0x18 */
	  __RW TIM_CCMR_IN_t CCMR1_IN;          /*!< TIM  capture/compare mode register 1,        Address offset: 0x18 */
  };
  union{
	  __RW TIM_CCMR_OUT_t CCMR2_OUT;   /*!< TIM  capture/compare mode register 2,        Address offset: 0x1C */
	  __RW TIM_CCMR_IN_t CCMR2_IN;          /*!< TIM  capture/compare mode register 2,        Address offset: 0x1C */
  };
  __RW uint32_t CCER;            /*!< TIM capture/compare enable register,         Address offset: 0x20 */
  __RW uint32_t CNT;             /*!< TIM counter register,                        Address offset: 0x24 */
  __RW uint32_t PSC;             /*!< TIM prescaler register,                      Address offset: 0x28 */
  __RW uint32_t ARR;             /*!< TIM auto-reload register,                    Address offset: 0x2C */
  __RW uint32_t RCR;             /*!< TIM  repetition counter register,            Address offset: 0x30 */
  __RW uint32_t CCR[4];          /*!< TIM capture/compare register 1,2,3,4         Address offset: 0x34, 0x38, 0x3C, 0x40 */
  __RW uint32_t BDTR;            /*!< TIM break and dead-time register,            Address offset: 0x44 */
  __RW uint32_t DCR;             /*!< TIM DMA control register,                    Address offset: 0x48 */
  __RW uint32_t DMAR;            /*!< TIM DMA address for full transfer register,  Address offset: 0x4C */
  __RW uint32_t OR;              /*!< TIM option register,                         Address offset: 0x50 */
}TIM_t;

/*!-----------VARIABLES GLOBALES PRIVADAS-------------------------------------------------------------------*/
volatile TIM_t *TIM_REG[4] = {
		((TIM_t *)TIM1_BASE),
		((TIM_t *)TIM2_BASE),
		((TIM_t *)TIM3_BASE),
		((TIM_t *)TIM4_BASE)
};
/*!-----------VARIABLES GLOBALES PUBLICAS-------------------------------------------------------------------*/

/*!-----------FUNCIONES/macros-------------------------------------------------------------------------------------*/

///general
inline void TIM_setPeriod(uint8_t timN, uint16_t val){
	TIM_REG[timN]->ARR = val;
}

inline void TIM_setCountMode(uint8_t timN, uint8_t mode){
	TIM_REG[timN]->CR1.Direction = mode;
}

inline void TIM_autoReload_en(uint8_t timN){
	TIM_REG[timN]->CR1.AR_en = 1;
}

inline void TIM_counter_en(uint8_t timN){
	TIM_REG[timN]->CR1.Counter_en = 1;
}



//for PWM
inline void TIM_setPLL(uint8_t timN, uint16_t val){
	TIM_REG[timN]->PSC = val;
}

inline void TIM_setClockDiv(uint8_t timN, uint8_t val){
	TIM_REG[timN]->CR1.Clock_div = val;
}

inline void TIM_setActiveHigh(uint8_t timN, uint8_t chnl){
	TIM_REG[timN]->CCER &= (1 << (CCER_POLAR_BIT + 4*chnl));
}

inline void TIM_output_en(uint8_t timN, uint8_t chnl){
	TIM_REG[timN]->CCER &= (1 << (CCER_OUT_EN_BIT + 4*chnl));
}

inline void TIM_setVal(uint8_t timN, uint8_t chnl, uint16_t val){
	TIM_REG[timN]->CCR[chnl] = val;
}


//for encoder mode
inline void TIM_setSlaveMode(uint8_t timN, uint8_t val){
	TIM_REG[timN]->SMCR |= val;
}

inline void TIM_setInput_NInv(uint8_t timN, uint8_t chnl){
	TIM_REG[timN]->CCER &= (1 << (CCER_POLAR_BIT + 4*chnl));
}

inline uint16_t TIM_getCount(uint8_t timN, uint8_t chnl){
	TIM_REG[timN]->CCR[chnl];
}

void TIM_setSel(uint8_t timN, uint8_t chn, uint8_t sel){
	switch(chn){
	case CHN1_MODE:		TIM_REG[timN]->CCMR1_OUT.chnA_sel = sel;	break;
	case CHN2_MODE:		TIM_REG[timN]->CCMR1_OUT.chnB_sel = sel;	break;
	case CHN3_MODE:		TIM_REG[timN]->CCMR2_OUT.chnA_sel = sel;	break;
	case CHN4_MODE:		TIM_REG[timN]->CCMR2_OUT.chnB_sel = sel;	break;
	}
}

void TIM_setOutputMode(uint8_t timN, uint8_t chn, uint8_t mode){
	switch(chn){
	case CHN1_MODE:		TIM_REG[timN]->CCMR1_OUT.chnA_mode = mode;	break;
	case CHN2_MODE:		TIM_REG[timN]->CCMR1_OUT.chnB_mode = mode;	break;
	case CHN3_MODE:		TIM_REG[timN]->CCMR2_OUT.chnA_mode = mode;	break;
	case CHN4_MODE:		TIM_REG[timN]->CCMR2_OUT.chnB_mode = mode;	break;
	}
}

void TIM_setInputPLL(uint8_t timN, uint8_t chn, uint8_t pll){
	switch(chn){
	case CHN1_MODE:		TIM_REG[timN]->CCMR1_IN.chnA_Input_PLL = pll;	break;
	case CHN2_MODE:		TIM_REG[timN]->CCMR1_IN.chnB_Input_PLL = pll;	break;
	case CHN3_MODE:		TIM_REG[timN]->CCMR2_IN.chnA_Input_PLL = pll;	break;
	case CHN4_MODE:		TIM_REG[timN]->CCMR2_IN.chnB_Input_PLL = pll;	break;
	}
}

void TIM_preloadEn(uint8_t timN, uint8_t chn){
	switch(chn){
	case CHN1_MODE:		TIM_REG[timN]->CCMR1_OUT.chnA_preLd_en = 1;	break;
	case CHN2_MODE:		TIM_REG[timN]->CCMR1_OUT.chnA_preLd_en = 1;	break;
	case CHN3_MODE:		TIM_REG[timN]->CCMR1_OUT.chnA_preLd_en = 1;	break;
	case CHN4_MODE:		TIM_REG[timN]->CCMR1_OUT.chnA_preLd_en = 1;	break;
	}

}

#ifdef __cplusplus
}
#endif
