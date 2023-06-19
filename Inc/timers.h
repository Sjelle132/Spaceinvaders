/*
 * timers.h
 *
 *  Created on: Jun 7, 2023
 *      Author: oscar
 */

#ifndef TIMERS_H_
#define TIMERS_H_

#include "pins.h"

#include "stm32f30x_conf.h"

typedef struct{
	int16_t hours,minutes,seconds,hndrseconds,miliseconds,flag;
} timeS_t;



extern timeS_t tid;
extern volatile uint32_t elapsed_time;
extern volatile uint32_t elapsed_time_enemy;
extern volatile uint32_t elapsed_time_PlayerBullet;
extern volatile uint32_t elapsed_time_Asteroid;
extern volatile uint32_t elapsed_time_Boss;


void configTimer();
void TIM1_BRK_TIM15_IRQHandler(void);
void prntClk();
int32_t returnSec();
int32_t returnMilisec();
int32_t returnHNDR();
//void clockCounter(timeS_t* tid);
void tidCalc (timeS_t* tid);





#endif /* TIMERS_H_ */
