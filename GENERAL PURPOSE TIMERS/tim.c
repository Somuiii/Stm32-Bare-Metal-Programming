#include "stm32f4xx.h"

#define TIM2_EN 		(1U << 0)
#define Count_EN 		(1U << 0)


void tim2_1hz(void){

	/* 1. Enable clock access */
	RCC->APB1ENR |= TIM2_EN;

	/* 2. Set prescaler value */
	TIM2->PSC = 1600 - 1 ;     //16 000 000	/ 1 600 = 10 000

	/* 3. Set auto reload value */
	TIM2->ARR = 10000 - 1;	   // 10 000 / 10 000 = 1

	/* 4. Clear counter */
	TIM2->CNT = 0;

	/* 5. Enable timer */
	TIM2->CR |= Count_EN;

}
