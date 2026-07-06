/*
 * adc.h
 *
 *  Created on: 06-Jul-2026
 *      Author: somsh
 */

#ifndef INC_ADC_H_
#define INC_ADC_H_

#include "stm32f4xx.h"
#include<stdint.h>
void ADC_Innit(void);
void ADC_Start_Con(void);
uint32_t ADC_Read(void);

#endif /* INC_ADC_H_ */
