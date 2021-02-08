/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Damian Melamed
 * @brief          : Main program
 ******************************************************************************
 */
#include <DR_h/HAL/RHAL.h>

void ms_func(void){
	//TODO: everything
}

void loop_func(void){

}

int main(void){
	RHAL hal;

	while(1){
		hal.do_every_1ms(&ms_func);
		hal.do_loop(&loop_func);
	}

}
