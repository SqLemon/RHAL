/*
 * DR_Software_timer.c
 *
 *  Created on: 5 ene. 2021
 *      Author: Damian Melamed
 */


/*!-----------INCLUDES PRIVADOS-----------------------------------------------------------------------------*/
#include <DR_h/Hardware/DR_Software_Timer.h>
/*!-----------DEFINES Y MACROS PRIVADOS---------------------------------------------------------------------*/
#define PauseTmr(b)		(SW_TmrPlay &= ~(1 << b))
#define PlayTmr(b)		(SW_TmrPlay |= (1 << b))
#define TmrPlayState(b)	((SW_TmrPlay >> b) & 0x01)

#define setTmrFlag(b)	(SW_TmrFlags |= (1 << b))
#define clrTmrFlag(b)	(SW_TmrFlags &= ~(1 << b))
#define TmrFlagState(b)	((SW_TmrFlags >> b) & 0x01)

#define setTmrUsed(b)	(SW_TmrFlags |= (1 << b))
#define clrTmrUsed(b)	(SW_TmrFlags &= ~(1 << b))
/*!-----------TIPOS DE DATOS PRIVADOS-----------------------------------------------------------------------*/

/*!-----------VARIABLES GLOBALES PRIVADAS-------------------------------------------------------------------*/

/*!-----------VARIABLES GLOBALES PUBLICAS-------------------------------------------------------------------*/
static uint16_t SW_TmrTime[ N_TIMERS ];
static void (*SW_TmrFunc[ N_TIMERS ])(void);
static uint32_t SW_TmrFlags = 0, SW_TmrPlay = 0;
volatile uint8_t SW_TmrUsed = 0;
/*!-----------FUNCIONES-------------------------------------------------------------------------------------*/


inline uint8_t TmrUsed(uint8_t b){ return((SW_TmrUsed >> b) & 0x01); };
inline uint8_t TmrFull(){ return(SW_TmrUsed == 0xFFFFFFFF); };


/**
	@fn  TimerStart
	@brief incializa un contador de tiempo con una funcion a ejecutar cuando este termina.
 	@author Damian Melamed
 	@param [in] número de evento/contador.
 	@param [in] tiempo a contar (en décimas, segundos o minutos).
 	@param [in] fúncion a ejecutar cuando haya pasado el tiempo especificado.
	@return 0 si algo salió mal
*/
uint8_t SW_Timer_Start ( uint8_t event_n , uint16_t t , void (* f_event )(void)){
	if((event_n < N_TIMERS) && (SW_TmrUsed != 0xFFFFFFFF)){
		SW_TmrFunc[event_n] = f_event;
		SW_TmrTime[event_n] = t;
		PlayTmr(event_n);

		setTmrUsed(event_n);
		return 1;
	}

	return 0;
}


/**
	@fn  TimerPause
	@brief Pausa el conteo del tiempo del número de contador especificado
 	@author Damian Melamed
 	@param [in] número de evento/contador.
 	@param [in] modo. USAR DEFINES "PAUSE" y "PLAY".
	@return 0 si el contador especificado no existe
*/
uint8_t SW_Timer_Pause ( uint8_t event_n , uint8_t modo ){
	if((event_n < N_TIMERS) && (SW_TmrTime[event_n])){
		if(modo) PlayTmr(event_n);
		else PauseTmr(event_n);

		return 1;
	}
	return 0;
}



/**
	@fn  TimerStop
	@brief elimina el contador especificado
 	@author Damian Melamed
 	@param [in] número de evento/contador
	@return 0 si el contador especificado no existe
*/
uint8_t SW_Timer_Stop ( uint8_t event_n  ){
	if((event_n < N_TIMERS) && (SW_TmrTime[event_n])){
		SW_TmrTime[event_n] = 0;
		clrTmrFlag(event_n);
		PauseTmr(event_n);
		SW_TmrFunc[event_n] = (void *) 0;

		clrTmrUsed(event_n);
		return 1;
	}
	return 0;
}


/**
	@fn  TimerSet
	@brief setea un nuevo tiempo de conteo a un contador ya creado
 	@author Damian Melamed
 	@param número de evento/contador.
 	@param nuevo tiempo
	@return -1 si el contador especificado no existe o no fue creado con TimerStart()
*/
uint8_t SW_Timer_Set ( uint8_t event_n , uint32_t t ){
	if((event_n < N_TIMERS) && SW_TmrTime[event_n]){
		SW_TmrTime[event_n] = t;
		return 1;
	}
	return 0;
}


/**
	@fn  TimerGet
	@brief getea el tiempo restante para que termine el contador
 	@author Damian Melamed
 	@param [in] número de evento/contador.
 	@param [out] tiempo restante para que termine el contador
	@return -1 si el contador especificado no existe o no fue creado con TimerStart()
*/
int16_t SW_Timer_Get ( uint8_t event_n){
	if((event_n < N_TIMERS) && SW_TmrTime[event_n]){
		return SW_TmrTime[event_n];
	}
	return -1;
}


/**
	@fn  TimerClose
	@brief termina con todos los timers.
 	@author Damian Melamed
*/
void SW_Timer_Close ( void ){
	for(uint8_t i = 0; i < N_TIMERS; i++)
		SW_Timer_Stop(i);
}

//<<<<<<<<<<<<<<<<<funciones para funcionamiento>>>>>>>>>>>>>>>>>>>//

/**
	@fn  TimerDiscount
	@brief descuenta 1 a los valors restantes de tiempo de los contadores.
 	@author Damian Melamed
*/
void SW_Timer_Discount ( void ){
	if(SW_TmrPlay){	//si algun software timer está siendo utilizado. Si no, no recorre el for loop}
		for(uint8_t i = 0; i < N_TIMERS; i ++){
			if((SW_TmrTime[i]) && (TmrPlayState(i))){
				SW_TmrTime[i]--;
				if(!SW_TmrTime[i])	setTmrFlag(i);
			}
		}
	}
}

/**
	@fn  TimerRun
	@brief ejecuta la funcion correpondiente cuando termina la cuenta
	@Pparam [in] número de evento/contador.
 	@author Damian Melamed
*/
void SW_Timer_Run(uint8_t event_n){
	if(event_n < N_TIMERS){
		if(TmrFlagState(event_n)){
			clrTmrFlag(event_n);
			SW_TmrFunc[event_n]();
		}
	}
}







