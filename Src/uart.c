/*
 * uart.c
 *
 *  Created on: 9. jun. 2023
 *      Author: oscar
 */

#include "uart.h"

int32_t keyboardController() {
	int8_t arrayBogstaver[256]; //not used
	int8_t *parray = arrayBogstaver; //not used
	int8_t bogstav = uart_get_char();
	int8_t directionsState = 0;
	int k = 0; //not used

	if (bogstav != NULL) {
		if (bogstav == 'w'){
			directionsState = 1;
		}else if (bogstav == 's'){
			directionsState = 2;
		}else if(bogstav == 'a'){
			directionsState = 4;
		}else if(bogstav == 'd'){
			directionsState = 8;
		}else if (bogstav == 'j'){
			directionsState = 64;
		}
	}
	return directionsState;
}

//for exercise, not used
void smthFunny1(){
	int8_t arrayBogstaver[256];
	int8_t *parray = arrayBogstaver;
	int8_t bogstav = uart_get_char();

	int k = 0;

	if (bogstav != NULL){
		*(parray+k) = bogstav;
		k++;

		printf("%s",arrayBogstaver);
		if (bogstav == 0x0D){
			bogstav = '\0';
			printf("%s", arrayBogstaver);
			clreol();
		}
	} arrayBogstaver[255]='\0';
}
