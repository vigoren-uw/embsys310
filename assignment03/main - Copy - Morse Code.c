
// Aaron Vigoren
// LD1 --> PA5 -- Homework
// 1. Follow the same steps as we did in the class to blink LED1 (PA5) at a visible rate.
// 2. Use the XOR bit wise operator to toggle the LED.

#if 1
#define RCC_BASE 0x40021000
#define RCC_AHB2ENR (*((unsigned int*)(RCC_BASE + 0x4C)))

#define GPIOA_BASE 0x48000000
#define GPIOA_MODER (*((unsigned int*)(GPIOA_BASE + 0x00)))
#define GPIOA_ODR (*((unsigned int*)(GPIOA_BASE + 0x14)))

volatile int counter=0;
//int counter=0;

#define ORD5 0x20
#define ON 0x20
#define OFF 0x00


void main(void)
{
    // RCC Base Address: 0x40021000
    // RCC AHB2 peripheral clock enable register (RCC_AHB2ENR)
    // Address offset: 0x4C
    // Set bit[1] to 1
    // 1. Enable clock to Peripheral
    // Value 0x1 to enable GPIOA
    RCC_AHB2ENR |= 0x1;
  
    // GPIOA Base Address: 0x48000000
    // GPIO port mode register (GPIOx_MODER) (x = A..E and H)
    // Address offset: 0x00
    // GPIOA: Set bit[11:10] to 0x01 to set mode to general purpose enable for PA5 0xABFFF7FF
    GPIOA_MODER = 0xABFFF7FF;

    // GPIOA Base Address: 0x48000000
    // GPIO port output data register (GPIOx_ODR) (x = A..E and H)
    // Address offset: 0x14
    // GPIOA Set bit[5] to 1 --> 0x20; // Turn LED ON
    // GPIOA Set bit[5] to 0 --> 0x00; // Turn LED OFF

    
    // dot  'o': 1unit = 100000
    // dash '-': 3unit = 300000
    // 1unit gap between symbols, dot or dash
    // 3unit gap between letters, A B C
    
    GPIOA_ODR = OFF;

    // Name to blink to LED1 in Morse Code: AARON
    // A: 'o -'
    // A: 'o -'
    // R: 'o - o'
    // O: '- - -'
    // N: '- o'


        // A: 'o -'
        
        // dot
        GPIOA_ODR = ON;  
        counter=0;
        while (counter < 100000)
        {
          counter++;
        }
        
        // gap between symbols
        GPIOA_ODR = OFF; 
        counter=0;
        while (counter < 100000)
        {
          counter++;
        }
        
        // dash
        GPIOA_ODR = ON;  
        counter=0;
        while (counter < 300000)
        {
          counter++;
        }
        
        // gap between letters
        GPIOA_ODR = OFF; 
        counter=0;
        while (counter < 300000)
        {
          counter++;
        }
        
        // A: 'o -'
        
        // dot
        GPIOA_ODR = ON;  
        counter=0;
        while (counter < 100000)
        {
          counter++;
        }
        
        // gap between symbols
        GPIOA_ODR = OFF; 
        counter=0;
        while (counter < 100000)
        {
          counter++;
        }
        
        // dash
        GPIOA_ODR = ON;  
        counter=0;
        while (counter < 300000)
        {
          counter++;
        }
        
        // gap between letters
        GPIOA_ODR = OFF; 
        counter=0;
        while (counter < 300000)
        {
          counter++;
        }
        
        // R: 'o - o'
        
        // dot
        GPIOA_ODR = ON;  
        counter=0;
        while (counter < 100000)
        {
          counter++;
        }
        
        // gap between symbols
        GPIOA_ODR = OFF; 
        counter=0;
        while (counter < 100000)
        {
          counter++;
        }
        
        // dash
        GPIOA_ODR = ON;  
        counter=0;
        while (counter < 300000)
        {
          counter++;
        }
        
        // gap between symbols
        GPIOA_ODR = OFF; 
        counter=0;
        while (counter < 100000)
        {
          counter++;
        }
        
        // dot
        GPIOA_ODR = ON;  
        counter=0;
        while (counter < 100000)
        {
          counter++;
        }

        // gap between letters
        GPIOA_ODR = OFF; 
        counter=0;
        while (counter < 300000)
        {
          counter++;
        }
        
        // O: '- - -'
        
        // dash
        GPIOA_ODR = ON;  
        counter=0;
        while (counter < 300000)
        {
          counter++;
        }
        
        // gap between symbols
        GPIOA_ODR = OFF; 
        counter=0;
        while (counter < 100000)
        {
          counter++;
        }
        
        // dash
        GPIOA_ODR = ON;  
        counter=0;
        while (counter < 300000)
        {
          counter++;
        }
        
        // gap between symbols
        GPIOA_ODR = OFF; 
        counter=0;
        while (counter < 100000)
        {
          counter++;
        }
        
        // dash
        GPIOA_ODR = ON;  
        counter=0;
        while (counter < 300000)
        {
          counter++;
        }

        // gap between letters
        GPIOA_ODR = OFF; 
        counter=0;
        while (counter < 300000)
        {
          counter++;
        }

        // N: '- o'
        
        // dash
        GPIOA_ODR = ON;  
        counter=0;
        while (counter < 300000)
        {
          counter++;
        }
        
        // gap between symbols
        GPIOA_ODR = OFF; 
        counter=0;
        while (counter < 100000)
        {
          counter++;
        }
        
        // dot
        GPIOA_ODR = ON;  
        counter=0;
        while (counter < 100000)
        {
          counter++;
        }
        
        // gap between letters
        GPIOA_ODR = OFF; 
        counter=0;
        while (counter < 300000)
        {
          counter++;
        }
        

        
}
#endif
