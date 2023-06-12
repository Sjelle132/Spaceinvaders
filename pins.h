/*
 * joystick.h
 *
 *  Created on: 7 Jun 2023
 *      Author: liou-
 */

#ifndef PINS_H_
#define PINS_H_
#include "stdio.h"
#include "stdint.h"
#include "stm32f30x_conf.h"


int32_t readJoystick();
void initPins();

#endif /* PINS_H_ */
