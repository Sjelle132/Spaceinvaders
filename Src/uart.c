/*
 * uart.c
 *
 *  Created on: 9. jun. 2023
 *      Author: oscar
 */

#include "uart.h"

int32_t keyboardController() {
    int8_t arrayBogstaver[256];
    int8_t *parray = arrayBogstaver;
    int8_t bogstav = uart_get_char();
    int8_t directionsState = 0;
    int k = 0;

    if (bogstav != NULL) {
        *(parray + k) = bogstav;
        k++;

       // printf("%s", arrayBogstaver);

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
    arrayBogstaver[255] = '\0';
    return directionsState;
}




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



/*
uint8_t smthFunny(){
	int k = 256;
	int8_t array[k];
	int8_t *parray = array;
	int8_t ch = uart_get_char();

	int count = 0;

	if (ch != NULL){
		array[count] = ch;
		count++;
	}


	for (int i = 0; i < k-2; i++){
		*(parray+i) = uart_get_char();

	}
	*(parray + 255) = 0;
	return *(parray);

}
*/










/*
 * void uart_init(uint32_t baud);
void uart_put_char(uint8_t c);
uint8_t uart_get_char();
uint8_t uart_get_count();
void uart_clear();
 */
