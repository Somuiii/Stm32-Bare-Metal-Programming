#include "stm32f4xx.h"
#define GPIOC_EN                (1 << 2)
#define PIN_13                  (1 << 13)
#define LED_PIN                 PIN_13

int main(){
    
    /*Enable clock access to Port C*/
    RCC->AHB1ENR    |=  GPIOC_EN;

    /*Set the mode register to Output*/
    GPIOC->MODER    &= ~(1U << 27);
    GPIOC->MODER    |=  (1U << 26);

    /*Set the LED pin to pull up or pull down*/
    GPIOC->PUPDR    |=  (1U << 27);
    GPIOC->PUPDR    &= ~(1U << 26); 

    while(1){

        GPIOC->ODR ^= LED_PIN;               //practise with bsrr once
        for(int i=0; i<99900; i++){
            
        }

    }
}