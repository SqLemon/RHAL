/*
 * DR_GPIO.c
 *
 *  Created on: Dec 29, 2020
 *  Author: Damian Melamed
 */

/*!-----------INCLUDES PRIVADOS-----------------------------------------------------------------------------*/
#include <DR_h/Hardware/DR_GPIO.h>

#ifdef __cplusplus
extern "C" {
#endif

/*!-----------DEFINES Y MACROS PRIVADOS---------------------------------------------------------------------*/
#define GPIO_BASE           (APB2_PERIPH_BASE + 0x00000800UL)	//Address del GPIO
#define GPIO				((GPIO_t *)GPIO_BASE)

/*!-----------TIPOS DE DATOS PRIVADOS-----------------------------------------------------------------------*/
typedef struct{
  __RW uint32_t CRL;	//port config - pines 0 a 7. Para configurar modo (input/output/pullup...)
  __RW uint32_t CRH;	//port config - pines 8 a 15.
  __R  uint32_t IDR;	//port input data
  __RW uint32_t ODR;	//port output data
  __W  uint32_t BSRR;	//atomic set/reset
  __W  uint32_t BRR;	//atomic reset
  __RW uint32_t LCKR;
  __R  uint32_t RESERVED[0xF6];
} GPIO_t;

/*!-----------VARIABLES GLOBALES PRIVADAS-------------------------------------------------------------------*/

/*!-----------VARIABLES GLOBALES PUBLICAS-------------------------------------------------------------------*/

/*!-----------FUNCIONES-------------------------------------------------------------------------------------*/


/*!<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>!*/
/*!<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>!*/
/* De los registros de configuracion, los bits estan distribuidos de la siguiente forma:
 * 		0:1 -> MODE.
 * 				Si es '0': el pin es un INPUT
 * 				Si es '1': es OUTPUT con Fmax de 10MHz
 *		1:2 -> CNF
 *				si es input y '0': es "analog"
 *				si es Input y '1': es "floating"
 *				si es input y '2': es "pull-up" o "pull-Down"
 * 						si ODR es '0'  ->  pull down
 * 						si ODR es '1'  ->  pull up
 *
 *		son 4 bits por cada pin distribuidos en 2 registros.
 */
/*!<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>!*/
/*!<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>!*/




/** @brief 	setea un pin como entrada o salida
 *  @param	Puerto del pin que se quiere congurar
 *  @param 	Número de pin a configurar
 *  @param	Modo. USAR DEFINES INPUT y OUTPUT
 */
void GPIO_setDir(uint8_t port, uint8_t pin, uint8_t mode){
	//Pongo los de modo en 0 para luego poder escribir
	//Quedan definidos como entradas
	if(pin > 7)		GPIO[port].CRH &= ~(0x03 << (pin*4));
	else			GPIO[port].CRL &= ~(0x03 << (pin*4));

	if(mode == OUTPUT){
		if(pin > 7)	GPIO[port].CRH |= (0x01 << (pin*4));
		else		GPIO[port].CRL |= (0x01 << (pin*4));
		return;
	}
	else{
		//ya está configurado como input. Dejo esto por si se necesita discriminar cuando el pin está configurado como entrada
		return;
	}
}



/** @brief 	poner un pin configurado como input en pullup, pul down, etc
 *  @param	Puerto del pin que se quiere congurar
 *  @param 	Número de pin a configurar
 *  @param	Modo. USAR DEFINES INPUT_PULLUP, INPUT_PULLDOWN, INPUT_FLOATING e INPUT_ANALOG
 */
void GPIO_setInputMode(uint8_t port, uint8_t pin, uint8_t mode){
	//---reset bits to be set
	//pongo en 0 los bits de crl.cnf. Está configurado como analog
	GPIO[port].ODR	&= ~(1 << pin);

	if(pin > 7)		GPIO[port].CRH &= ~(0x03 << ((pin*4)+2));
	else			GPIO[port].CRL &= ~(0x03 << ((pin*4)+2));

	//---choose values
	uint8_t cnf_value, odr_value = 0;
	switch(mode){
		case INPUT_PULLUP:		cnf_value = 0b10;		odr_value = 1;	 	break;
		case INPUT_PULLDOWN:	cnf_value = 0b10;		odr_value = 0;	 	break;
		case INPUT_FLOATING:	cnf_value = 0b01;		odr_value = 0;	 	break;
		case INPUT_ANALOG:		cnf_value = 0b00;		odr_value = 0;	 	break;
	}

	//---set bits
	if(pin > 7)		GPIO[port].CRH |= (cnf_value << ((pin*4)+2));
	else			GPIO[port].CRL |= (cnf_value << ((pin*4)+2));

	if(odr_value)	GPIO[port].ODR |= (1 << pin);
}



/** @brief 	poner un pin configurado como OUTPUT en push-pull o opendrain
 *  @param	Puerto del pin que se quiere congurar
 *  @param 	Número de pin a configurar
 *  @param	Modo. USAR DEFINES OUTPUT_PUSHPULL y OUTPUT_OPENDRAIN
 */
void GPIO_setOutputMode(uint8_t port, uint8_t pin, uint8_t mode){
	//---reset bits to be set
	//pongo en 0 los bits de crl.cnf. Está configurado como analog
	if(pin > 7)		GPIO[port].CRH &= ~(0x03 << ((pin*4)+2));
	else			GPIO[port].CRL &= ~(0x03 << ((pin*4)+2));

	//---choose values
	uint8_t cnf_value;
	switch(mode){
		case OUTPUT_PUSHPULL:	cnf_value = 0b00;		break;
		case OUTPUT_OPENDRAIN:	cnf_value = 0b01; 		break;
	}

	//---set bits
	if(pin > 7)		GPIO[port].CRH |= (cnf_value << ((pin*4)+2));
	else			GPIO[port].CRL |= (cnf_value << ((pin*4)+2));
}



/** @brief poner un pin configurado con funcion alternativa en push-pull o opendrain
 *  @param	Puerto del pin que se quiere congurar
 *  @param 	Número de pin a configurar
 *  @param	Modo. USAR DEFINES OUTPUT_PUSHPULL y OUTPUT_OPENDRAIN
 */
void GPIO_setAltMode(uint8_t port, uint8_t pin, uint8_t mode){
	//---reset bits to be set
	//pongo en 0 los bits de crl.cnf. Está configurado como analog
	if(pin > 7)		GPIO[port].CRH &= ~(0x03 << ((pin*4)+2));
	else			GPIO[port].CRL &= ~(0x03 << ((pin*4)+2));

	//---choose values
	uint8_t cnf_value;
	switch(mode){
		case ALTERNATE_PUSHPULL:	cnf_value = 0b10;	 	break;
		case ALTERNATE_OPENDRAIN:	cnf_value = 0b11;	 	break;
	}

	//---set bits
	if(pin > 7)		GPIO[port].CRH |= (cnf_value << ((pin*4)+2));
	else			GPIO[port].CRL |= (cnf_value << ((pin*4)+2));
}




/*!<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>!*/
/*!<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>!*/
/* Para dsetear o resetear un pin se usa el registro de atomic set. Cada pin tiene asociados 2 bits.
 * Uno en los primeros 16 bits del registro y otro en los segundos 16 biuts. El primero se usa para setear y el segundo para resetear
 * Ej para pin 0
 * 		bit 0  -> set
 * 		bit 16 -> clr
 *
 *
 * Cuando un pin está configurado como input, el estado del pin, setá guardado en el Input data register (IDR). Hay un bit por pin.
 * Los 16 bits mas significativos son reservados
 *
 * Cuando un pin está configurado como output, el estado del pin está guardado en el Output Data register (ODR)
 */
/*!<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>!*/
/*!<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>!*/



/** @brief 	setea un pin como entrada o salida
 *  @param	Puerto del pin que se quiere congurar
 *  @param 	Número de pin a configurar
 *  @param	Modo. USAR DEFINES HIGH y LOW
 */
void GPIO_setPin(uint8_t port, uint8_t pin, uint8_t val){
	if(val == HIGH)		GPIO[port].BSRR |= (1 << pin);
	else if(val == LOW)	GPIO[port].BSRR |= (1 << (pin+16));
}



/** @brief devuelve el estado del pin Cuando está configurado como input
 *  @param	Puerto del pin que se quiere congurar
 *  @param 	Número de pin a configurar
 *  @return estado del pin. DEFINES HIGH y LOW
 */
uint8_t GPIO_getPin(uint8_t port, uint8_t pin){
	return ((GPIO[port].IDR >> pin) & 0x01);
}



/** @brief devuelve el estado del pin Cuando está configurado como output
 *  @param	Puerto del pin que se quiere congurar
 *  @param 	Número de pin a configurar
 *  @return estado del pin. DEFINES HIGH y LOW
 */
uint8_t GPIO_getStatus(uint8_t port, uint8_t pin){
	return ((GPIO[port].ODR >> pin) & 0x01);
}

#ifdef __cplusplus
}
#endif
