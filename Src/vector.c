/*
 * vector.c
 *
 *  Created on: Jun 6, 2023
 *      Author: oscar
 */
#include "vector.h"

void initVector(vector_t* v) {
			v->x = 0;
			v->y = 0;
			}

int32_t rotateVector(vector_t* v, uint8_t deg) {

	int32_t cosVal = expand(cosCalc(deg));
	int32_t sinVal = expand(sinCalc(deg));

	int32_t newX = ((v->x * cosVal)>>16) - ((v->y * sinVal)>>16) ;
	int32_t newY = ((v->x * sinVal)>>16)  + ((v->y * cosVal)>>16 ) ;

	v->x = newX;
	v->y = newY;

}

