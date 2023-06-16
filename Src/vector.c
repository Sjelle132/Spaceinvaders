/*
 * vector.c
 *
 *  Created on: 6 Jun 2023
 *      Author: liou-
 */
#include "vector.h"

void printVector(vector_t v){
	printFix(expand(v.x));
	printFix(expand(v.y));
}

void initVector (vector_t* v){
	v->x = 0;
	v->y = 0 ;
}

void rotateVector(vector_t* vec, int32_t deg){
//	int32_t sinVal = expand(calcSin(deg));
//	int32_t cosVal = expand(calcCos(deg));

	/*
	vec->x = ((vec->x * cosVal) >> 16) - ((vec->y * sinVal) >> 16);
	vec->y = ((vec->x * sinVal) >> 16) + ((vec->y * cosVal) >> 16);
	*/

	int32_t oldX = vec->x;
	int32_t oldY = vec->y;

	vec->x = (FIX14_MULT(oldX, calcCos(deg)) - FIX14_MULT(oldY, calcSin(deg)));
	vec->y = (FIX14_MULT(oldX, calcSin(deg)) + FIX14_MULT(oldY, calcCos(deg)));
}


void printFix(int32_t i) {
// Prints a signed 16.16 fixed point number
	if ((i & 0x80000000) != 0) { // Handle negative numbers
		printf("-");
		i = ~i + 1;
	}
	printf("%ld.%04ld", i >> 16, 10000 * (uint32_t)(i & 0xFFFF) >> 16);
// Print a maximum of 4 decimal digits to avoid overflow
}

int32_t expand(int32_t i) {
// Converts an 18.14 fixed point number to 16.16
	return i << 2;
}

int32_t calcSin(int32_t number){
	/*if (number < 0) {
		return SIN[-number & 0x1FF];
	}*/
	return SIN[number & 0x1FF];
}

int32_t calcCos(int32_t number){
	/*if (number < 0) {
		return SIN[(-number + 128) & 0x1FF];
	}*/
	return SIN[(number + 128)& 0x1FF];
}
