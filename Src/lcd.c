/*
 * LCDfunc.c
 *
 *  Created on: 8 Jun 2023
 *      Author: liou-
 */

#include "lcd.h"

uint8_t buffer[512];

void initlcd(){
	lcd_init();
	memset(buffer,0x00,512);
	lcd_push_buffer(buffer);
}

void lcdWriteText(char TtD[], int line){
	int offset = line;
	for(int i = 0; i < strlen(TtD); i++){
		for(int j = 0; j < 5; j++){
			//character_data[[32;126]
			buffer[j+(5*i)+(128*offset)] = character_data[TtD[i]-32][j];
		}
	}
	lcd_push_buffer(buffer);
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

void lcdScoreDisplay(){
	int scoreOneOffset = 7;
	int scoreTenOffset = 6;
	int scoreOne = score % 10;
	int scoreTen = score / 10;

	for(int j = 0; j < 5; j++){
		buffer[j+(scoreOneOffset * 5)+(128 * 2)] = character_data[scoreOne + 16][j];
	}
	lcd_push_buffer(buffer);

	for(int j = 0; j < 5; j++){
		buffer[j+(scoreTenOffset * 5)+(128 * 2)] = character_data[scoreTen + 16][j];
	}
	lcd_push_buffer(buffer);
}

void lcdHealthDisplay(int8_t spaceship){
	lcdInstaDeath();
	for(int i = 0; i < spaceship; i++){
		for(int j = 0; j < 5; j++){
			//character_data[[32;126]
			buffer[j+ (40) + (i*5)] = character_data[42-32][j];
		}
	}
	lcd_push_buffer(buffer);
}

void lcdInstaDeath(){
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 5; j++){
			//character_data[[32;126]
			buffer[j + (40) + (i*5)] = character_data[32-32][j];
		}
	}
	lcd_push_buffer(buffer);
}
