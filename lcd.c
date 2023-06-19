/*
 * LCDfunc.c
 *
 *  Created on: 8 Jun 2023
 *      Author: liou-
 */

#include "charset.h"
#include "lcd.h"
#include "30010_io.h"
#include "stm32f30x_conf.h" // STM32 config
#include "stdio.h"
#include "stdint.h"
#include "string.h"

void lcd_write_text(char TtD[], int line){
	lcd_init();
	uint8_t buffer[512];
	memset(buffer,0x00,512);
	lcd_push_buffer(buffer);
	int offset = line;
	for(int i = 0; i < strlen(TtD); i++){
		for(int j = 0; j < 5;j++){
			//character_data[[32;126]
			buffer[j+(5*i)+(128*offset)] = character_data[TtD[i]-32][j];
		}
	}
	lcd_push_buffer(buffer);
}

void lcd_update(char TtD[], int line, int x){
	
}
