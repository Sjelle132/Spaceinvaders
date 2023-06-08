/*
 * ansi.h
 *
 *  Created on: 1. jun. 2023
 *      Author: oscar
 */

#ifndef _ANSI_H_
#define _ANSI_H_

/* Includes -------------------------------------------------------------*/
#include "stdint.h"
#include "stdio.h"
#include "stm32f30x_conf.h"
#include "lut.h"// Whatever needs to be included
/* Exported types -------------------------------------------------------*/
/* Exported constants ---------------------------------------------------*/
#define ESC 0x1B
/* Exported macro -------------------------------------------------------*/
//#define  // Whatever needs to be defined
/* Exported functions -------------------------------------------------- */
//void addWhateverFunctionsYouNeed( type parameter );
void fgcolor(uint8_t foreground);
void bgcolor(uint8_t background);
void color(uint8_t foreground, uint8_t background);
void clrscr();
void clreol();
void gotoxy(uint8_t r,uint8_t c);
void underline(uint8_t on);
void blink(uint8_t bl);
void inverse(uint8_t iv);
void clrpkt();
void hideCursor();

void drawvert(uint8_t n);
void drawhoriz(uint8_t n);
void initColor();


//window




#endif /* _ANSI_H_ */
