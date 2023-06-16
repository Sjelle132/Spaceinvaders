

#include "interrupts.h"


// sets up the TIM2 interrupt
void init_interrupts() {
	RCC->APB1ENR |= RCC_APB1Periph_TIM2; // Enable clock line to timer 2;


	TIM2->CR1 |= 0x0 << 11; // Configure timer 2
	TIM2->CR1 |= 0x00 << 8;
	TIM2->CR1 |= 0x0 << 7;
	TIM2->CR1 |= 0x0 << 5;
	TIM2->CR1 |= 0x0 << 4;
	TIM2->CR1 |= 0x0 << 3;
	TIM2->CR1 |= 0x0 << 2;
	TIM2->CR1 |= 0x0 << 1;
	TIM2->CR1 |= 0x1 << 0;
	// TIM2->CR1 |= 0x1 << 0;

	TIM2->ARR = 63999999 / 20; // Set reload value
	TIM2->PSC = 0; // Set prescale value

	TIM2->DIER |= 0x0001; // Enable timer 2 interrupts
	uint8_t priority = 0;
	NVIC_SetPriority(TIM2_IRQn, priority); // Set interrupt priority
	NVIC_EnableIRQ(TIM2_IRQn); // Enable interrupt

}



