/*
 * LCDfunc.h
 *
 *  Created on: 8 Jun 2023
 *      Author: liou-
 */

#ifndef LCDFUNC_H_
#define LCDFUNC_H_

#include "charset.h"
#include "lcd.h"
#include "30010_io.h"

#include "stm32f30x_conf.h" // STM32 config
#include "stdio.h"
#include "stdint.h"

void lcd_write_text(char TtD[], int line);
void lcd_update(char TtD[], int line,int x);

#endif /* LCDFUNC_H_ */
