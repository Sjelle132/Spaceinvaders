/*
 * timers.h
 *
 *  Created on: Jun 7, 2023
 *      Author: oscar
 */

#ifndef TIMERS_H_
#define TIMERS_H_

#include "stm32f30x_conf.h"

typedef struct{
	int32_t hours,minutes,seconds,miliseconds;
} timeS_t;



void configTimer();
void TIM1_BRK_TIM15_IRQHandler(void);
void prntClk();

timeS_t hejMorMor;


#endif /* TIMERS_H_ */
