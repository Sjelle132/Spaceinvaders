/*
 * LCDfunc.c
 *
 *  Created on: 8 Jun 2023
 *      Author: liou-
 */

#include "lcd.h"

lcd_t lcd;
uint8_t buffer[512];

void initlcd(lcd_t* lcd){
	lcd->i = 0;
	lcd->j = 0;
	lcd_init();
	memset(buffer,0x00,512);
	lcd_push_buffer(buffer);
}

void lcdWriteText(char TtD[], int line){
	int offset = line;
	for(lcd.i = 0; lcd.i < strlen(TtD); lcd.i++){
		for(lcd.j = 0; lcd.j < 5; lcd.j++){
			//character_data[[32;126]
			buffer[lcd.j+(5*lcd.i)+(128*offset)] = character_data[TtD[lcd.i]-32][lcd.j];
		}
	}
	lcd_push_buffer(buffer);
}

void lcd_update(){
	int offset = 3;
	if(tid.flag){
		//character_data[[32;126]
		buffer[lcd.j+(5*lcd.i)+(128*offset)] += character_data[50-32][lcd.j];
		lcd_push_buffer(buffer);
		tid.flag = 0;
	}
}

void lcdTimeDisplay(){
	int timeOffset = 1;
	int secOffset = 9;
	int minOffset = 6;

	int secOne = tid.seconds % 10;
	int secTen = tid.seconds / 10;
	int	minOne = tid.minutes % 10;
	int minTen = tid.minutes / 10;

	if(tid.flag){

		//Display the ones for second timer
		for(int j = 0; j < 5; j++){
			buffer[j+(5*secOffset)+(128*timeOffset)] = character_data[secOne+16][j];
		}

		lcd_push_buffer(buffer);

		//Displays the tens for second timer
		for(int j = 0; j < 5; j++){
			buffer[j+(5*secOffset - 5)+(128*timeOffset)] = character_data[secTen+16][j];
		}
		lcd_push_buffer(buffer);

		//Displays the tens for second timer
		for(int j = 0; j < 5; j++){
			buffer[j+(5*secOffset - 10)+(128*timeOffset)] = character_data[58-32][j];
		}
		lcd_push_buffer(buffer);

		//Displays the ones for minute timer
		for(int j = 0; j < 5; j++){
			buffer[j+(5*minOffset)+(128*timeOffset)] = character_data[minOne+16][j];
		}

		lcd_push_buffer(buffer);

		//Displays the tens for minute timer
		for(int j = 0; j < 5; j++){
			buffer[j+(5*minOffset - 5)+(128*timeOffset)] = character_data[minTen+16][j];
		}

		lcd_push_buffer(buffer);

		tid.flag = 0;
	}
}
