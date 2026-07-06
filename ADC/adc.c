#include "stm32f4xx.h"

#define ADC1_CLK	 (1U << 8)
#define GPIOA_EN	 (1U << 0)
#define ADC1_EN		 (1U << 0)
#define ADC_START	 (1U << 30)
#define ADC_CONT	 (1U << 1)	
#define ADC_CONV_END (1U << 1)

int main(){

}

void ADC_Innit(void){
	//-----------------Configure ADC GPIO PIN

	/* 1) Give clk access to gpio port for channel 0 adc */
	RCC->AHB1ENR |= GPIOA_EN;

	/* 2) Set GPIO to analog mode */
	GPIOA->MODER |=  (1U << 3);
	GPIOA->MODER |=  (1U << 2);

	//-----------------Configure ADC module

	/* 1) Give clk access to adc1 module*/
	RCC->APB2ENR |= ADC1_CLK;

	//-----------------Configure ADC parameters
	/* 1) Conversion sequence start */
	ADC1->SQR3 = (1U << 0);				//USE BINARY NUMBERS HERE, IMAGINE THE SQR1 is a priority list

	/* 2) Conversion sequence length */
	ADC1->SQR1 = 0x00;    				// as we are using only 1 channel, also refer ADC_SQR1

	/* 3) Enable ADC*/
	ADC1->CR2 |=  ADC1_EN;

	/* 4) Conversion sequence end */
	ADC1->CR2 |=  (1U << 10);

}

uint32_t ADC_Read(void){

	while(!(ADC1->SR & ADC_CONV_END)){}
	return (ADC1->DR) ;

}

void ADC_Start_Con(void){

	//ADC1->CR2 |= ADC_CONT;                                  //this is for continuous ADC conversion 
	ADC1->CR2 |= ADC_START;

}
