/*
 * uart.h
 *
 *  Created on: 03-Jul-2026
 *      Author: somsh
 */

#ifndef INC_UART_H_
#define INC_UART_H_
#include "stm32f4xx.h"

void USART2_tx_Init(void);
char USART2_read(void);
void USART2_rxtx_Init(void);



#endif /* INC_UART_H_ */
