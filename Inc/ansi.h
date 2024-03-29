/*
 * ansi.h
 *
 *  Created on: 1 Jun 2023
 *      Author: liou-
 */

#ifndef ANSI_H_
#define ANSI_H_


/* Includes -------------------------------------------------------------*/
#include "stdio.h"
#include "stm32f30x_conf.h"
#include "stdint.h"// Whatever needs to be included
#include "lut.h"
#include "math.h"

/* Exported types -------------------------------------------------------*/
/* Exported constants ---------------------------------------------------*/
#define ESC 0x1B
#define LUTSIN_H
#define M_PI 3.14159265358979323846

/* Exported macro -------------------------------------------------------*/
//#define // Whatever needs to be defined
/* Exported functions -------------------------------------------------- */

void resetbgcolor();
void fgcolor(uint8_t foreground);
void bgcolor(uint8_t background);
void color(uint8_t foreground, uint8_t background);
void clrscr();
void clreol();
void gotoxy(uint8_t r, uint8_t c);
void underline(uint8_t on);
void blink(uint8_t on);
void inverse(uint8_t on);
void clrpkt();
void hideCursor();

#endif /* _ANSI_H_ */
