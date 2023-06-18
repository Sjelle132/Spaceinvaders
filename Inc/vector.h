/*
 * vector.h
 *
 *  Created on: 6 Jun 2023
 *      Author: liou-
 */


#ifndef VECTOR_H_
#define VECTOR_H_
#include "stdio.h"
#include "stm32f30x_conf.h"
#include "stdint.h"// Whatever needs to be included
#include "lut.h"
#include "math.h"
#include "ansi.h"


/* Exported types -------------------------------------------------------*/
/* Exported constants ---------------------------------------------------*/
#define ESC 0x1B
#define LUTSIN_H
#define M_PI 3.14159265358979323846
#define FIX14_SHIFT 14
#define FIX14_MULT(A, B) ( (A)*(B) >> FIX14_SHIFT)
#define FIX14_DIV(A, B) (((A) << FIX14_SHIFT)/B)

typedef struct{
	int32_t x, y;
} vector_t;

void initVector(vector_t* v);
void rotateVector(vector_t* vec, int32_t deg);
void printVector(vector_t v);
void printFix(int32_t i);
int32_t expand(int32_t i);
int32_t calcSin(int32_t number);
int32_t calcCos(int32_t number);

#endif /* VECTOR_H_ */
