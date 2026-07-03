//USART1
//Port = A ; Pin - 2 (Tx)[1 0] , Pin - 3 (Rx)[1 0]

#include "stm32f4xx.h"
#include "uart.h"
#include<stdio.h>

#define GPIOC_EN 			(1U << 3)
#define GPIOC_13			(1U << 13)
#define LED_PIN 			GPIOC_13

char key;

int main(){

	RCC->AHB1ENR |= GPIOC_EN;

	GPIOC->MODER &=  ~(1U << 27);
	GPIOC->MODER |=   (1U << 26);

	USART2_rxtx_Init();

	while(1){
		key = USART2_read();
		if (key == '1'){

			GPIOC->ODR |= ~LED_PIN;
		}
		else{
			GPIOC->ODR &= ~(~LED_PIN);
		}

		//printf("Hello from STM32 \n\r");  use this for receiver

	}
}



