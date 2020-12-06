#include <stdint.h>

// LD1 --> PA5 -- Homework
// LD2 --> PB14 -- In Class

#define RCC_BASE 0x40021000
#define RCC_AHB2ENR (*((unsigned int*)(RCC_BASE + 0x4C)))
#define p_RCC_AHB2ENR ((unsigned int*)(RCC_BASE + 0x4C)) // pointer need to pass addresses into registers  

#define GPIOB_BASE 0x48000400
#define GPIOB_MODER (*((unsigned int*)(GPIOB_BASE + 0x00)))
#define GPIOB_ODR (*((unsigned int*)(GPIOB_BASE + 0x14)))

#define GPIOA_BASE 0x48000000
#define GPIOA_MODER (*((unsigned int*)(GPIOA_BASE + 0x00)))
#define GPIOA_ODR (*((unsigned int*)(GPIOA_BASE + 0x14)))
#define p_GPIOA_ODR ((unsigned int*)(GPIOA_BASE + 0x14)) // pointer need to pass addresses into registers 

#define ORD14   (1<<14)
#define ORD5    (1<<5)

#define LED_1_ON 1
#define LED_1_OFF 0
#define DELAY_DURATION 3

void delay(int iteration);
void control_user_led1(int state, uint32_t duration, unsigned int* GPIOA_ODR_pointer); // pointer need to pass addresses into registers 
void enable_rcc(unsigned int* port); // pointer need to pass addresses into registers 

void main(void)
{    
    // RCC AHB2 peripheral clock enable for Porta
    enable_rcc(p_RCC_AHB2ENR);
  
    // GPIO port mode register (GPIOx_MODER) (x = A..E and H)
    // GPIOA Base Address: 0x48000000
    // Address offset: 0x00
    // Set bit[11:10] to 0x01  so --> 0x400 // To enable PA5 as output
    // Note: GPIOA_MODER reset value = 0xABFFFFFF
    //       So will only need to clear bit 11
    GPIOA_MODER &= 0xFFFFF7FF;
     
    // Toggle LED_1 ON/OFF at specified DELAY_DURATION
    while(1)
    {
      control_user_led1(LED_1_ON,  DELAY_DURATION, p_GPIOA_ODR);
      control_user_led1(LED_1_OFF, DELAY_DURATION, p_GPIOA_ODR);
    }
}
