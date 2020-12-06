#include <stdint.h>
#include "delay.h"
//#include "stm32f401xe.h"    // CMSIS - Device Specific File
#include "system_stm32l4xx.h"
#include "stm32l475xx.h"

// LD1 --> PA5 -- Homework
// LD2 --> PB14 -- In Class

volatile int counter=0;

void main(void)
{     

    // RCC AHB2 peripheral clock enable register (RCC_AHB2ENR)
    // **** Bit definition for RCC_AHB2ENR register ****/ 
    // RCC Base Address: 0x40021000
    // RCC AHB2 peripheral clock enable register (RCC_AHB2ENR)
    // Address offset: 0x4C
    // Set bit[1] to 1
    // 1. Enable clock to Peripheral
    // Value 0x1 to enable GPIOA
  
    RCC->AHB2ENR |= RCC_AHB2ENR_GPIOAEN;

    // General Purpose IO - GPIO port mode register (GPIOx_MODER) (x = A..E and H)
    // **** Bits definition for GPIO_MODER register ****/
    // GPIOA Base Address: 0x48000000
    // GPIO port mode register (GPIOx_MODER) (x = A..E and H)
    // Address offset: 0x00
    // GPIOA: Set bit[11:10] to 0x01 to set mode to general purpose enable for PA5 0xABFFF7FF
    
    GPIOA->MODER &= ~GPIO_MODER_MODE5_1;
    GPIOA->MODER |= GPIO_MODER_MODE5_0;
    
    // GPIO port output data register (GPIOx_ODR) (x = A..E and H)
    // **** Bits definition for GPIO_ODR register ****/
    // GPIOA Base Address: 0x48000000
    // GPIO port output data register (GPIOx_ODR) (x = A..E and H)
    // Address offset: 0x14
    // GPIOA Set bit[5] to 1 --> 0x20; // Turn LED ON
    // GPIOA Set bit[5] to 0 --> 0x0; // Turn LED OFF
    
    while(1)
    {
        
        GPIOA->ODR |= GPIO_ODR_OD5;
        delay(100000);
        
        GPIOA->ODR &= ~GPIO_ODR_OD5;
        delay(100000);
        
    }    

}
