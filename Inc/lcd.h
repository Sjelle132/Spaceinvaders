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

typedef struct{
	int i, j;
} lcd_t;

void initlcd();
void lcdWriteText(char TtD[], int line);
void lcd_update(); //Isn't used
void lcdTimeDisplay();

#endif /* LCDFUNC_H_ */
