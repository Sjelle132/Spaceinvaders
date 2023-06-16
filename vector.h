/*
 * vector.h
 *
 *  Created on: 14. jun. 2023
 *      Author: filip
 */

#ifndef VECTOR_H_
#define VECTOR_H_
#define FIX14_SHIFT 14
#define FIX14_MULT(a, b) ( (a)*(b) >> FIX14_SHIFT )
#define FIX14_DIV(a, b) ( ((a) << FIX14_SHIFT) / b )
#include "stm32f30x_conf.h"
#include <stdint.h>
#include "LUTSIN.h"
int32_t sinus(int deg);

typedef struct{
	int32_t x,y;
} vector_t;


void printVector(vector_t v);
void initVector(vector_t *v);
void rotateVector(vector_t *v,int32_t deg);



#endif /* VECTOR_H_ */
