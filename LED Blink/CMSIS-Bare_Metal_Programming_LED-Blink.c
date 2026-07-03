// Where is the LED connect on the mcu 
// Port C , Pin 13

#include "stm32f4xx.h"

#define PERIPHERAL_BASE_ADDR            (0x40000000UL)
#define PERIPHERAL_OFFSET_ADDR          (0x00020000UL)
#define AHB1_BASE_ADDR                  (PERIPHERAL_BASE_ADDR + PERPHERAL_OFFSET_ADDR)
#define GPIOC_OFFSET_ADDR               (0x00000800UL)
#define GPIO_C_BASE_ADDR                (AHB1_BASE_ADDR + GPIOC_OFFSET_ADDR)
#define RCC_OFFSET_ADDR                 (0x00003800UL)
#define RCC_BASE_ADDR                   (AHB1_BASE_ADDR + RCC_OFFSET_ADDR)
#define RCC_ENABLE_OFFSET_ADDR          (0x00000030UL)
#define RCC_AHB1ENR_ADDR_R              (*(volatile unsigned int*))(RCC_BASE_ADDR + RCC_OFFSET_ADDR)
#define GPIOC_EN                        (1U << 2)
#define GPIOC_MODER_OFFSET_ADDR         (0x00000000UL)
#define GPIOC_MOD_R                     (*(volatile unsigned int*))(GPIOC_BASE_ADDR + GPIOC_MODER_OFFSET_ADDR)
#define ODR_OFFSET_ADDR                 (0x00000014UL)
#define ODR_BASE_ADDR_R                 (*(volatile unsigned int*))(GPIOC_BASE_ADDR + ODR_OFFSET_ADDR)
#define PIN_13                          (1U << 13)
#define LED_PIN                         PIN_13

int main(){

/* 1) Enable clock access to GPIO_C */
    RCC_AHB1ENR_ADDR_R |= GPIO_CEN;

/* 2) Set PC13 as o/p pin */
    GPIOC_MOD_R |=  (1U << 26);
    GPIOC_MOD_R &= ~(1U << 27);

/* 3) Set PC13 to pullup mode */
    //PUPDR_BASE_ADDR_R &= ~(1U << 27);
    //PUPDR_BASE_ADDR_R |=  (1U << 26);

while(1){
    // 3) Set PC13 HIGH
    //ODR_BASE_ADDR_R |= ~LED_PIN;   //because our humble black pill has active low led that is why we are using NOT operation
    ODR_BASE_ADDR_R ^= LED_PIN;   //for toggling the led

for(int i=0; i<999000;i++){

        }   
    }
}