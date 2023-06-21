/*
 * LCDfunc.h
 *
 *  Created on: 8 Jun 2023
 *      Author: liou-
 */

#ifndef LCDFUNC_H_
#define LCDFUNC_H_

#include "charset.h"
#include "30010_io.h"
#include "stm32f30x_conf.h" // STM32 config
#include "stdio.h"
#include "stdint.h"
#include "string.h"
#include "timers.h"


extern uint8_t buffer[];
extern int score;

void initlcd();
void lcdWriteText(char TtD[], int line);
void lcdTimeDisplay();
void lcdScoreDisplay();
void lcdHealthDisplay(int8_t spaceship);
void lcdInstaDeath();

#endif /* LCDFUNC_H_ */
