/*
 * timers.h
 *
 *  Created on: Jun 7, 2023
 *      Author: oscar
 */

#ifndef TIMERS_H_
#define TIMERS_H_

#include "stm32f30x_conf.h"
#include "pins.h"
#include "ansi.h"


typedef struct{
	int16_t hours, minutes, seconds, miliseconds, flag;
} timeS_t;

extern timeS_t tid;

void configTimer();
void TIM1_BRK_TIM15_IRQHandler(void);
void prntClk();
int32_t returnSec();
int32_t returnMilisec();

#endif /* TIMERS_H_ */
