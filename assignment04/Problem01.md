

Problems:

1. Follow the same steps as we did in the class to blink LED1 (PA5) at a visible rate using the bit-band region to enable the clock to Port A, then answer the following:

	// RCC_AHB2ENR bit-banding

	// bit_word_addr = bit_band_base + (byte_offset*32) + (bit_number*4)

	#define bit_band_base 0x42000000

	#define byte_offset 0x2104C

	#define bit_number 0 //bit number for GPIOA PA5 LED1

	#define RCC_AHB2ENR (*((unsigned int*)(bit_band_base + (byte_offset*0x20) + (bit_number*0x4))))

	#define GPIOA_BASE 0x48000000

	#define GPIOA_MODER (*((unsigned int*)(GPIOA_BASE + 0x00)))

	#define GPIOA_ODR (*((unsigned int*)(GPIOA_BASE + 0x14)))

	volatile int counter=0;
	
	#define ORD5 0x20

	void main(void)

	{

	// Set bit[1] to 1

	// 1. Enable clock to Peripheral

	// Value 0x1 to enable GPIOA
  
	// *** Using RCC_AHB2ENR aliasing bit-banding ***

	RCC_AHB2ENR = 0x1;

	...

a) What instructions does the compiler produce in assembly for “writing” to the GPIO bit when using bit-band address?

Dissassembly instructions below in figures. Note red errow - we have 0x4242'0980 with bit-banding and RCC_AHB2ENR without bit-banding.

![Disassembly screenshot](https://github.com/vigoren-uw/embsys310/blob/main/assignment04/gpioa_WITH_bitbanding1.JPG)
![Disassembly screenshot](https://github.com/vigoren-uw/embsys310/blob/main/assignment04/gpioa_WITH_bitbanding2.JPG)

b) What were the instructions produced when writing to the GPIOx_ODR without using bit-banding?

Dissassembly instructions below in figures. Note red errow - we have 0x4242'0980 with bit-banding and RCC_AHB2ENR without bit-banding.

![Disassembly screenshot](https://github.com/vigoren-uw/embsys310/blob/main/assignment04/gpioa_NO_bitbanding1.JPG)
![Disassembly screenshot](https://github.com/vigoren-uw/embsys310/blob/main/assignment04/gpioa_NO_bitbanding2.JPG)

