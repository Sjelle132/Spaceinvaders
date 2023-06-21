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
#include "string.h"

#ifndef WINDOW_H_
#define WINDOW_H_

void initWindow();
void windowName(uint32_t x1, uint32_t y1, uint32_t x2, uint32_t y2, char s[], int style);
void windowFrame(uint32_t x1, uint32_t y1, uint32_t x2, uint32_t y2, int style);
void nameOnly(uint8_t x, uint8_t y, char string[]);
void windowMainMenu();
void windowHelp();
void windowGame();
void windowSelDif();
void windowStart();
void windowGameOver();

#endif /* WINDOW_H_ */
