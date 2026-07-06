#include<stdio.h>
#include "stm32f4xx.h"
#include "adc.h"
#include "uart.h"

int main(){

	USART2_tx_Init();
	ADC_Innit();
	//ADC_Start_Con();			// for continuous conversion

	while(1){

		uint32_t sensor_values;
		ADC_Start_Con();
		sensor_values = ADC_Read();
		printf("Sensor values = %d",sensor_values);

	}
}
