/*
 * timers.c
 *
 *  Created on: Jun 7, 2023
 *      Author: oscar
 */


void configTimer(){
	RCC->APB2ENR |= RCC_APB2Periph_TIM15; // Enable clock line to timer 15;
	TIM15->CR1 = 0; // Configure timer 15
	TIM15->ARR = 63000; // Set reload value (63000)
	TIM15->PSC = 0; // Set prescale value
	TIM15->DIER |= 0x0001; // Enable timer 15 interrupts
	TIM15->CR1 = 1; // Configure timer 15

	NVIC_SetPriority(TIM1_BRK_TIM15_IRQn, priority); // Set interrupt priority
	NVIC_EnableIRQ(TIM1_BRK_TIM15_IRQn); // Enable interrupt
}

void TIM1_BRK_TIM15_IRQHandler(void) {
 //Do whatever you want here, but make sure it doesn’t take too much time
TIM15->SR &= ~0x0001; // Clear interrupt bit
}

