/*
 * timers.c
 *
 *  Created on: Jun 7, 2023
 *      Author: oscar
 */

#include "timers.h"
#include "pins.h"

timeS_t hejMorMor = {0,0,0,0};

void configTimer(){
	RCC->APB2ENR |= RCC_APB2Periph_TIM15; // Enable clock line to timer 15;
	TIM15->CR1 = 0; // Configure timer 15
	TIM15->ARR = 63000; // Set reload value (63000)
	TIM15->PSC = 0; // Set prescale value
	TIM15->DIER |= 0x0001; // Enable timer 15 interrupts
	TIM15->CR1 = 1; // Configure timer 15

	NVIC_SetPriority(TIM1_BRK_TIM15_IRQn, 0); // Set interrupt priority
	NVIC_DisableIRQ(TIM1_BRK_TIM15_IRQn); // Disable interrupt
}

void TIM1_BRK_TIM15_IRQHandler(void) {

	hejMorMor.miliseconds++;
	if (hejMorMor.miliseconds == 1000){
		hejMorMor.seconds++;
		hejMorMor.miliseconds = 0;
	}else if (hejMorMor.seconds == 60){
		hejMorMor.minutes++;
		hejMorMor.seconds = 0;
	}else if (hejMorMor.minutes == 60){
		hejMorMor.hours++;
		hejMorMor.minutes = 0;
	} else {
		hejMorMor.miliseconds = hejMorMor.miliseconds;
		hejMorMor.seconds = hejMorMor.seconds;
		hejMorMor.minutes = hejMorMor.minutes;
		hejMorMor.hours = hejMorMor.hours;
	}
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
		printf("%02d:%02d:%02d:%03d",hejMorMor.hours,hejMorMor.minutes,hejMorMor.seconds,hejMorMor.miliseconds);


	}else if (joystickState == 8){
		gotoxy(1,3);
		printf("%02d:%02d:%02d:%03d",hejMorMor.hours,hejMorMor.minutes,hejMorMor.seconds,hejMorMor.miliseconds);


	}else if (joystickState == 2){
		NVIC_DisableIRQ(TIM1_BRK_TIM15_IRQn);
		enableSomething = 0;
		hejMorMor.hours = 0;
		hejMorMor.minutes = 0;
		hejMorMor.seconds = 0;
		hejMorMor.miliseconds = 0;
		gotoxy(1,1);
		printf("%02d:%02d:%02d",hejMorMor.hours,hejMorMor.minutes,hejMorMor.seconds);
		gotoxy(1,2);
		printf("%02d:%02d:%02d:%03d",hejMorMor.hours,hejMorMor.minutes,hejMorMor.seconds,hejMorMor.miliseconds);
		gotoxy(1,3);
		printf("%02d:%02d:%02d:%03d",hejMorMor.hours,hejMorMor.minutes,hejMorMor.seconds,hejMorMor.miliseconds);
	}else {
		gotoxy(1,1);
		printf("%02d:%02d:%02d",hejMorMor.hours,hejMorMor.minutes,hejMorMor.seconds);

	}
}




