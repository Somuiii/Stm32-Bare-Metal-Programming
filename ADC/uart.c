#include "uart.h"


#define GPIOA_EN		 (1 << 0)
#define USART2_EN 		 (1 << 17)
#define SYS_FREQ		 16000000
#define APB1_Clk		 SYS_FREQ
#define UART_BaudRate 	 115200
#define CR1TE_EN 		 (1 << 3)
#define CR1UE_EN 		 (1 << 13)
#define SR_TXE			 (1 << 7)

static void uart_set_baudrate(USART_TypeDef *USARTx, uint32_t PeriphClk, uint32_t BaudRate);
static uint16_t compute_uart_bd(uint32_t PeriphClk, uint32_t BaudRate);
void USART2_tx_Init(void);
void USART2_write(int ch);

int __io_char(int ch){
	USART2_write(ch);
	return ch;
}
void USART2_tx_Init(void){

	//-----------Configure the UART GPIO pin

	/* Enable RCC clock access to GPIO A port */
	RCC->AHB1ENR |= GPIOA_EN;
	/* Set PA2 to alternate function */
	GPIOA->MODER |=  (1 << 5);
	GPIOA->MODER &= ~(1 << 4);
	/* Set PA2 alternate mode to UART_TX (AF07) AFRL2 cuz we are using usart2 */
	GPIOA->AFR[0] |=  (1 << 8);
	GPIOA->AFR[0] |=  (1 << 9);
	GPIOA->AFR[0] |=  (1 << 10);
	GPIOA->AFR[0] &= ~(1 << 11);

	//-----------Configure UART module
	/* Enable clock access to uart2  */
	RCC->APB1ENR |= USART2_EN;
	/* Configure baud rate */
	uart_set_baudrate(USART2, APB1_Clk, UART_BaudRate);
	/* Configure Transfer direction*/
	USART2->CR1 = CR1TE_EN;
	/* Enable UART module */
	USART2->CR1 |= CR1UE_EN;
}

void USART2_write(int ch){
	/* Make sure transmit reg is empty*/
	while(!(USART2->SR & SR_TXE)){}
	/*Write to transmit data reg*/
	USART2->DR = (ch & 0xFF);   //data reg
}


static void uart_set_baudrate(USART_TypeDef *USARTx, uint32_t PeriphClk, uint32_t BaudRate){

	USARTx->BRR = compute_uart_bd(PeriphClk, BaudRate);

}

static uint16_t compute_uart_bd(uint32_t PeriphClk, uint32_t BaudRate){

	return ((PeriphClk + (BaudRate/2U))/BaudRate) ;

}
