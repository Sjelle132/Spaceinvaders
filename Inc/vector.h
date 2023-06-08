/*
 * vector.h
 *
 *  Created on: Jun 6, 2023
 *      Author: oscar
 */

#ifndef VECTOR_H_
#define VECTOR_H_
#include "stm32f30x_conf.h"

typedef struct {
	int32_t x, y;
	} vector_t;

	void initVector(vector_t* v);
	int32_t rotateVector(vector_t* v, uint8_t deg);



#endif /* VECTOR_H_ */
