#include<stdio.h>
#include "stm32f4xx.h"
#include "adc.h"
#include "uart.h"
#include "tim.h"

#define GPIOA_EN	(1U << 13)
#define LED_PIN 	(1U << 13)

int main(){

	RCC->AHB1ENR |= GPIOA_EN;

	GPIOA->MODER |=  (1U << 10);
	GPIOA->MODER &= ~(1U << 11);

	USART2_tx_Init();
	tim2_1hz();

	while(1){

		while( !(TIM2->SR & SR_UIF) ){
		}
		/* Clear UIF */
		TIM2->SR &= SR_UIF;

		printf("A sec has passed!");
		GPIOA->ODR ^= LED_PIN;
	}
}
