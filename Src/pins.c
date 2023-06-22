/*
 * joystick.c
 *
 *  Created on: 7 Jun 2023
 *      Author: liou-
 */

#include <pins.h>

#define JOYSTICK_UP_PIN 0
#define JOYSTICK_DOWN_PIN 1
#define JOYSTICK_LEFT_PIN 2
#define JOYSTICK_RIGHT_PIN 3
#define JOYSTICK_CENTER_PIN 4

//not used
int32_t readJoystick(){
	RCC->AHBENR |= RCC_AHBPeriph_GPIOA | RCC_AHBPeriph_GPIOB | RCC_AHBPeriph_GPIOC; // Enable clock for GPIO Port A

	uint8_t previousJoyStickState = 0;
	uint8_t joyStickState = 0;

	//Initialize pins
	joyStickState += (GPIOA->IDR >> 4) & 1 << JOYSTICK_UP_PIN;
	joyStickState += (GPIOB->IDR & 1) << JOYSTICK_DOWN_PIN;
	joyStickState += ((GPIOC->IDR >> 1) & 1 )*2*JOYSTICK_LEFT_PIN;
	joyStickState += (GPIOC->IDR & 1) << JOYSTICK_RIGHT_PIN;
	joyStickState += ((GPIOB->IDR >> 5) & 1 )*4*JOYSTICK_LEFT_PIN;

	//Falling edge detection
	if (previousJoyStickState != joyStickState){
		printf("%d", joyStickState);
	}
	previousJoyStickState = joyStickState;

	return previousJoyStickState;
}


//not used, for exercise
void setLed(){

	int16_t joystickState = readJoystick();

	//pin up
	if (joystickState == 1){
		GPIOA->ODR = (0x0000 << 9);
		GPIOB->ODR |= (0x0001 << 4);
		GPIOC->ODR |= (0x0001 << 7);

		//pin down
	} else if (joystickState == 2){
		GPIOA->ODR |= (0x0001 << 9);
		GPIOB->ODR = (0x0000 << 4);
		GPIOC->ODR |= (0x0001 << 7);

		//pin left
	} else if (joystickState == 4){
		GPIOA->ODR |= (0x0001 << 9);
		GPIOB->ODR |= (0x0001 << 4);
		GPIOC->ODR = (0x0000 << 7);

		//pin right
	} else if (joystickState == 8){
		GPIOA->ODR |= (0x0001 << 9);
		GPIOB->ODR = (0x0000 << 4);
		GPIOC->ODR = (0x0000 << 7);

		//pin center
	} else if (joystickState == 16){
		GPIOA->ODR = (0x0000 << 9);
		GPIOB->ODR = (0x0000 << 4);
		GPIOC->ODR |= (0x0001 << 7);

	} else {
		GPIOA->ODR = (0x0000 << 9);
		GPIOB->ODR = (0x0000 << 4);
		GPIOC->ODR = (0x0000 << 7);
	}
}


void setLedForGame(int8_t f){
	if (f == 0) {
		//set LED to pink
		GPIOA->ODR |= (0x0001 << 9);
		GPIOC->ODR |= (0x0001 << 7);
	} else {
		//clears registers
		GPIOA->ODR &= ~(0x0001 << 9);
		GPIOC->ODR &= ~(0x0001 << 7);
	}

	if (f == 1) {
		//set LED to green
		GPIOA->ODR |= (0x0001 << 9);
		GPIOB->ODR |= (0x0001 << 4);
	} else {
		//clears registers
		GPIOA->ODR &= ~(0x0001 << 9);
		GPIOB->ODR &= ~(0x0001 << 4);
	}
}



void initPins(){
	RCC->AHBENR |= RCC_AHBPeriph_GPIOA | RCC_AHBPeriph_GPIOB | RCC_AHBPeriph_GPIOC; // Enable clock for GPIO Port

	GPIOA->OSPEEDR &= ~(0x00000003 << (9 * 2)); // Clear speed register
	GPIOA->OSPEEDR |= (0x00000002 << (9 * 2)); //Set speed register
	GPIOB->OSPEEDR &= ~(0x00000003 << (4 * 2)); // Clear speed register
	GPIOB->OSPEEDR |= (0x00000002 << (4 * 2)); //Set speed register
	GPIOC->OSPEEDR &= ~(0x00000003 << (7 * 2)); // Clear speed register
	GPIOC->OSPEEDR |= (0x00000002 << (2 * 2)); //Set speed register

	GPIOA->OTYPER &= ~(0x0001 << (9 * 1)); //Clear output type register
	GPIOA->OTYPER |= (0x0000 << (1)); //Set output type register (0x00)
	GPIOB->OTYPER &= ~(0x0001 << (4 * 1)); //Clear output type register
	GPIOB->OTYPER |= (0x0000 << (1)); //Set output type register (0x00)
	GPIOC->OTYPER &= ~(0x0001 << (7 * 1)); //Clear output type register
	GPIOC->OTYPER |= (0x0000 << (1)); //Set output type register (0x00)

	GPIOA->MODER &= ~(0x00000003 << (9 * 2)); //Clear mode register
	GPIOA->MODER |= (0x00000001 << (9 * 2)); //Set mode register
	GPIOB->MODER &= ~(0x00000003 << (4 * 2)); //Clear mode register
	GPIOB->MODER |= (0x00000001 << (4 * 2)); //Set mode register
	GPIOC->MODER &= ~(0x00000003 << (7 * 2)); //Clear mode register
	GPIOC->MODER |= (0x00000001 << (7 * 2)); //Set mode register

}

