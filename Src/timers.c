/*
 * timers.c
 *
 *  Created on: Jun 7, 2023
 *      Author: oscar
 */

#include "timers.h"

//different global variables for time
volatile uint32_t elapsed_time_playerBullet = 0;
volatile uint32_t elapsed_time_enemyBullet = 0;
volatile uint32_t elapsed_time_enemyMovement = 0;
volatile uint32_t elapsed_time_bossBullet = 0;
volatile uint32_t elapsed_time_bossMovement = 0;
volatile uint32_t elapsed_time_asteroid = 0;
volatile uint32_t elapsed_time_powerup = 0;

	timeS_t tid = {0,0,0,0,0,0};

//init time to 00:00:00
void resetTimers(){
	tid.miliseconds = 0;
	tid.seconds = 0;
	tid.hndrseconds = 0;
	tid.minutes = 0;
	tid.hours = 0;
	tid.flag = 0;
}

void configTimer(){
	RCC->APB2ENR |= RCC_APB2Periph_TIM15; // Enable clock line to timer 15;
	TIM15->CR1 = 0; // Configure timer 15
	TIM15->ARR = 63000; // Set reload value (63000)
	TIM15->PSC = 0; // Set prescale value
	TIM15->DIER |= 0x0001; // Enable timer 15 interrupts

	NVIC_SetPriority(TIM1_BRK_TIM15_IRQn, 0); // Set interrupt priority
	NVIC_EnableIRQ(TIM1_BRK_TIM15_IRQn); // Enable interrupt
}

void TIM1_BRK_TIM15_IRQHandler(void) {

	//time for LCD display
	tid.miliseconds++;
	if (tid.miliseconds == 100){
		tid.hndrseconds++;
		tid.miliseconds = 0;

	} else if(tid.hndrseconds == 10){
		tid.seconds++;
		tid.hndrseconds = 0;
	}
	else if (tid.seconds == 60){
		tid.minutes++;
		tid.seconds = 0;
	} else if (tid.minutes == 60){
		tid.hours++;
		tid.minutes = 0;
	} else {
		tid.miliseconds = tid.miliseconds;
		tid.seconds = tid.seconds;
		tid.minutes = tid.minutes;
		tid.hours = tid.hours;
	}

	//increment the time variables
	elapsed_time_playerBullet++;
	elapsed_time_enemyBullet++;
	elapsed_time_enemyMovement++;
	elapsed_time_bossBullet++;
	elapsed_time_bossMovement++;
	elapsed_time_asteroid++;
	elapsed_time_powerup++;

	//set flag high for lcdTimeDisplay under lcd.c
	tid.flag = 1;

	TIM15->SR &= ~0x0001; // Clear interrupt bit
}



//for exercise, not used
int enableSomething = 0;

void prntClk(){
	int32_t joystickState = readJoystick();
	gotoxy(5,5);
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
		gotoxy(5,5);
		printf("%02d:%02d:%02d",tid.hours,tid.minutes,tid.seconds);

	}
}

//return the time data
int32_t returnSec(){
	return tid.seconds;
}

int32_t returnMilisec(){
	return tid.miliseconds;
}

int32_t returnHNDR(){
	return tid.hndrseconds;
}
