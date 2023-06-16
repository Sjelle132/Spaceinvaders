/*
 * window.h
 *
 *  Created on: 8 Jun 2023
 *      Author: liou-
 */

#include "stm32f30x_conf.h" // STM32 config
#include "30010_io.h" // Input/output library for this course
#include "ansi.h"
#include "stdio.h"
#include "stdint.h"

#ifndef WINDOW_H_
#define WINDOW_H_

void initWindow(uint8_t x1, uint8_t y1 ,uint8_t x2, uint8_t y2);

#endif /* WINDOW_H_ */
