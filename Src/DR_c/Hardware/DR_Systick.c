/*
 * DR_Systick.c
 *
 *  Created on: Dec 30, 2020
 *  Author: Damian Melamed
 */


/*!-----------INCLUDES PRIVADOS-----------------------------------------------------------------------------*/
#include <DR_h/Hardware/DR_Systick.h>


#ifdef __cplusplus
extern "C" {
#endif

/*!-----------DEFINES Y MACROS PRIVADOS---------------------------------------------------------------------*/
#define SYSTICK_BASE 	(0xE000E010UL)
#define SYSTICK		((STK_t *) SYSTICK_BASE)

/*!-----------TIPOS DE DATOS PRIVADOS-----------------------------------------------------------------------*/
typedef struct{
	uint32_t STK_enable:	1;  //habilitar el Systick
	uint32_t TICK_int:		1;  //habilitar las interrupciones del sytick
	uint32_t CLK_SOURCE:	1;  //seleccionar el src del sytick (la frecuencia del procesador normal o /8)
	uint32_t RESERVED0:		13;
	uint32_t Count_flag:	1;  //flag de cuenta. '1' si la cuenta llego a 0
	uint32_t RESERVED1:		15;
} STK_ctrl_t;


typedef struct{
	__RW STK_ctrl_t STK_CTRL;	//control. Mapa de bits STK_Ctrl
	__RW uint32_t STK_LOAD;		//Valor a comparar para generar la interrupcion
	__RW uint32_t STK_VAL;		//Valor acutual del contador
	__R  uint32_t STK_CALIB;	//Valor de fabrica de calibracion.  1ms a 9MHz (72Mhz / 8).
}STK_t;
/*!-----------VARIABLES GLOBALES PRIVADAS-------------------------------------------------------------------*/

/*!-----------VARIABLES GLOBALES PUBLICAS-------------------------------------------------------------------*/

/*!-----------FUNCIONES-------------------------------------------------------------------------------------*/

/** @brief 	Inicializa el systick con interrupciones cada 1ms
 *
 */
void Systick_init(void){
	SYSTICK->STK_LOAD = SYSTICK->STK_CALIB * 8;  //cargo el valor a copmarar para que genere una interrupcion cada 1ms
	SYSTICK->STK_CTRL.CLK_SOURCE = 1;			 //Elijo que sume al contador con la frecuencia del procesador (72Mhz)
	SYSTICK->STK_VAL = 0;						 //Pongo el contador en 0
	SYSTICK->STK_CTRL.TICK_int = 1;				 //Habilito las interrupciones
	SYSTICK->STK_CTRL.STK_enable = 1;			 //Habilito el Systick

}

/** @brief 	Systick handler
 *
 */
void SysTick_Handler(void){
	main_flags.Systick_ms = 1;	//pongo flag en 1 para avisar que pasó 1ms
}

#ifdef __cplusplus
}
#endif
