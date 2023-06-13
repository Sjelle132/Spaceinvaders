/*
 * timers.c
 *
 *  Created on: Jun 7, 2023
 *      Author: oscar
 */

#include "timers.h"

timeS_t tid = {0,0,0,0,0};

void configTimer(){
	RCC->APB2ENR |= RCC_APB2Periph_TIM15; // Enable clock line to timer 15;
	TIM15->CR1 = 0; // Configure timer 15
	TIM15->ARR = 63000; // Set reload value (63000)
	TIM15->PSC = 0; // Set prescale value
	TIM15->DIER |= 0x0001; // Enable timer 15 interrupts
	TIM15->CR1 = 1; // Configure timer 15

	NVIC_SetPriority(TIM1_BRK_TIM15_IRQn, 0); // Set interrupt priority
	NVIC_EnableIRQ(TIM1_BRK_TIM15_IRQn); // Enable interrupt
}

void TIM1_BRK_TIM15_IRQHandler(void) {
	tid.miliseconds++;
	if (tid.miliseconds == 1000){
		tid.seconds++;
		tid.miliseconds = 0;
		//tid.flag = 1;
	}else if (tid.seconds == 60){
		tid.minutes++;
		tid.seconds = 0;
	}else if (tid.minutes == 60){
		tid.hours++;
		tid.minutes = 0;
	} else {
		tid.miliseconds = tid.miliseconds;
		tid.seconds = tid.seconds;
		tid.minutes = tid.minutes;
		tid.hours = tid.hours;
	}

	//set flag high for lcdTimeDisplay under lcd.c
	tid.flag = 1;

	TIM15->SR &= ~0x0001; // Clear interrupt bit
}

int enableSomething = 0;

void prntClk(){
	int32_t joystickState = readJoystick();
	gotoxy(1,4);
	printf("%d",enableSomething);

	if (joystickState == 16){
		if(enableSomething == 1){
			NVIC_DisableIRQ(TIM1_BRK_TIM15_IRQn);
			enableSomething = 0;
		} else {
			NVIC_EnableIRQ(TIM1_BRK_TIM15_IRQn);
			enableSomething = 1;
		}

	}else if (joystickState == 4){
		gotoxy(1,2);
		printf("%02d:%02d:%02d:%03d",tid.hours,tid.minutes,tid.seconds,tid.miliseconds);

	}else if (joystickState == 8){
		gotoxy(1,3);
		printf("%02d:%02d:%02d:%03d",tid.hours,tid.minutes,tid.seconds,tid.miliseconds);

	}else if (joystickState == 2){
		NVIC_DisableIRQ(TIM1_BRK_TIM15_IRQn);
		enableSomething = 0;
		tid.hours = 0;
		tid.minutes = 0;
		tid.seconds = 0;
		tid.miliseconds = 0;
		gotoxy(1,1);
		printf("%02d:%02d:%02d",tid.hours,tid.minutes,tid.seconds);
		gotoxy(1,2);
		printf("%02d:%02d:%02d:%03d",tid.hours,tid.minutes,tid.seconds,tid.miliseconds);
		gotoxy(1,3);
		printf("%02d:%02d:%02d:%03d",tid.hours,tid.minutes,tid.seconds,tid.miliseconds);

	}else {
		gotoxy(1,1);
		printf("%02d:%02d:%02d",tid.hours,tid.minutes,tid.seconds);

	}
}

int32_t returnSec(){
	return tid.seconds;
}

int32_t returnMilisec(){
	return tid.miliseconds;
}
