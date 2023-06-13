/*
 * pins.c
 *
 *  Created on: Jun 6, 2023
 *      Author: oscar
 */

#include "pins.h"

#define JOYSTICK_UP_PIN 0
#define JOYSTICK_DOWN_PIN 1
#define JOYSTICK_LEFT_PIN 2
#define JOYSTICK_RIGHT_PIN 3
#define JOYSTICK_CENTER_PIN 4


void initPins(){
	RCC->AHBENR |= RCC_AHBPeriph_GPIOA | RCC_AHBPeriph_GPIOB | RCC_AHBPeriph_GPIOC; // Enable clock for GPIO Port A
		GPIOA->OSPEEDR &= ~(0x00000003 << (9 * 2)); // Clear speed register
		GPIOA->OSPEEDR |= (0x00000002 << (9 * 2)); // set speed register
		GPIOB->OSPEEDR &= ~(0x00000003 << (4 * 2)); // Clear speed register
		GPIOB->OSPEEDR |= (0x00000002 << (4 * 2)); // set speed register
		GPIOC->OSPEEDR &= ~(0x00000003 << (7 * 2)); // Clear speed register
		GPIOC->OSPEEDR |= (0x00000002 << (7	 * 2)); // set speed register

		GPIOA->OTYPER &= ~(0x0001 << (9 * 1)); // Clear output type register
		GPIOA->OTYPER |= (0x0000 << (1)); // Set output type register (0x00
		GPIOB->OTYPER &= ~(0x0001 << (4 * 1)); // Clear output type register
		GPIOB->OTYPER |= (0x0000 << (1)); // Set output type register (0x00
		GPIOC->OTYPER &= ~(0x0001 << (7 * 1)); // Clear output type register
		GPIOC->OTYPER |= (0x0000 << (1)); // Set output type register (0x00

		GPIOA->MODER &= ~(0x00000003 << (9 * 2)); // Clear mode register
		GPIOA->MODER |= (0x00000001 << (9 * 2)); // Set mode register
		GPIOB->MODER &= ~(0x00000003 << (4 * 2)); // Clear mode register
		GPIOB->MODER |= (0x00000001 << (4 * 2)); // Set mode register
		GPIOC->MODER &= ~(0x00000003 << (7 * 2)); // Clear mode register
		GPIOC->MODER |= (0x00000001 << (7 * 2)); // Set mode register


}

int32_t readJoystick(){

	//RCC->AHBENR |= RCC_AHBPeriph_GPIOA | RCC_AHBPeriph_GPIOB | RCC_AHBPeriph_GPIOC; // Enable clock for GPIO Port A
	uint8_t joystickState = 0;
	joystickState += (GPIOA->IDR >>  4) & 1 << JOYSTICK_UP_PIN;
	joystickState += (GPIOB->IDR & 1) << JOYSTICK_DOWN_PIN;
	joystickState += ((GPIOC->IDR >>  1) & 1)*2*JOYSTICK_LEFT_PIN;
	joystickState += (GPIOC->IDR & 1) << JOYSTICK_RIGHT_PIN;
	joystickState += ((GPIOB->IDR >> 5) & 1)*4*JOYSTICK_CENTER_PIN;

	return joystickState;
}

void setLed(){

	int16_t joystickState = readJoystick();

	//pin up
	if (joystickState == 1){
		GPIOA->ODR = (0x0000 << 9);
		GPIOB->ODR |= (0x0001 << 4);
		GPIOC->ODR |= (0x0001 << 7);

		//pin down
		}else if (joystickState == 2){
			GPIOA->ODR |= (0x0001 << 9);
			GPIOB->ODR = (0x0000 << 4);
			GPIOC->ODR |= (0x0001 << 7);

		//pin left
		}else if (joystickState == 4){
			GPIOA->ODR |= (0x0001 << 9);
			GPIOB->ODR |= (0x0001 << 4);
			GPIOC->ODR = (0x0000 << 7);

		//pin right
		}else if (joystickState == 8){
			GPIOA->ODR |= (0x0001 << 9);
			GPIOB->ODR = (0x0000 << 4);
			GPIOC->ODR = (0x0000 << 7);

		//pin center
		}else if (joystickState == 16){
			GPIOA->ODR = (0x0000 << 9);
			GPIOB->ODR = (0x0000 << 4);
			GPIOC->ODR |= (0x0001 << 7);
		}else {
			GPIOA->ODR = (0x0000 << 9);
			GPIOB->ODR = (0x0000 << 4);
			GPIOC->ODR = (0x0000 << 7);
		}
	}


/*
void initPins(){
	RCC->AHBENR |= RCC_AHBPeriph_GPIOA; // Enable clock for GPIO Port A
	// Set pin PA0 to input
	GPIO[A-H]->MODER &= ~(0x00000003 << (pin * 2)); // Clear mode register
	GPIOA->MODER |= (0x00000000 << (0 * 2)); // Set mode register (0x00 –
	//Input, 0x01 - Output, 0x02 - Alternate Function, 0x03 - Analog in/out)
	GPIOA->PUPDR &= ~(0x00000003 << (0 * 2)); // Clear push/pull register
	GPIOA->PUPDR |= (0x00000002 << (0 * 2)); // Set push/pull register (0x00 -
	//No pull, 0x01 - Pull-up, 0x02 - Pull-down)
	uint16_t val = GPIOA->IDR & (0x0001 << pin); //Read from pin PA0
	// Set pin PA1 to output
	GPIOA->OSPEEDR &= ~(0x00000003 << (1 * 2)); // Clear speed register
	GPIOA->OSPEEDR |= (0x00000002 << (1 * 2)); // set speed register (0x01 - 10
	//MHz, 0x02 - 2 MHz, 0x03 - 50 MHz)
	GPIOA->OTYPER &= ~(0x0001 << (pin * 1)); // Clear output type register
	GPIOA->OTYPER |= (0x0000 << (1)); // Set output type register (0x00 -
	//Push pull, 0x01 - Open drain)
	GPIOA->MODER &= ~(0x00000003 << (1 * 2)); // Clear mode register
	GPIOA->MODER |= (0x00000001 << (1 * 2)); // Set mode register (0x00 –
	//Input, 0x01 - Output, 0x02 - Alternate Function, 0x03 - Analog in/out)
	GPIOA->ODR |= (0x0001 << 1); //Set pin PA1 to high
}
*/



