/*
 * vector.c
 *
 *  Created on: Jun 6, 2023
 *      Author: oscar
 */
#include "vector.h"
#include "fixpoint.h"

void printVector(vector_t v){
	printFix(expand(v.x));
	printFix(expand(v.y));
}
void initVector(vector_t* v) {
	v->x = 0;
	v->y = 0;
}

void rotateVector(vector_t *v, int32_t deg) {
	int32_t oldX = v->x;
	int32_t oldY = v->y;
	v->x = (FIX14_MULT(oldX, cosinus(deg)) - FIX14_MULT(oldY , sinus(deg)));
	v->y = (FIX14_MULT(oldX, sinus(deg))  + FIX14_MULT(oldY, cosinus(deg)));
}
