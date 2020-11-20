

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

Instructions in disassembly figures below. Note we have "0x4242'0980" with bit-banding and "RCC_AHB2ENR" without bit-banding in the instructions.

![Disassembly screenshot](https://github.com/vigoren-uw/embsys310/blob/main/assignment04/gpioa_WITH_bitbanding1.JPG)
![Disassembly screenshot](https://github.com/vigoren-uw/embsys310/blob/main/assignment04/gpioa_WITH_bitbanding2.JPG)

b) What were the instructions produced when writing to the GPIOx_ODR without using bit-banding?

Instructions in disassembly figures below. Note we have "0x4242'0980" with bit-banding and "RCC_AHB2ENR" without bit-banding in the instructions.

![Disassembly screenshot](https://github.com/vigoren-uw/embsys310/blob/main/assignment04/gpioa_NO_bitbanding1.JPG)
![Disassembly screenshot](https://github.com/vigoren-uw/embsys310/blob/main/assignment04/gpioa_NO_bitbanding2.JPG)


2. Create a function “func1” with 5 arguments and call “func1” from within another function “func2”. Trace thru the assembler and note:
	
	// fucntion declarations
 	
	int func2(void);
	
	int func1(int var0, int var1, int var2, int var3, int var4);
	
	void main(void)
	
	{
	
	  int variable = func2();
	
	  return;
	
	}

	// function sums five arguments and returns sum
	
	int func1(int var0, int var1, int var2, int var3, int var4)
	
	{
	
 	 int sum = var0 + var1 + var2 + var3 + var4;
 	
	 return sum;
	
	}
	
	// function calls func1 sum function, divides by 2 and returns value
	
	int func2(void)
	
	{
	
	int mvar1 = 1;
	
	int mvar2 = 1;
	
	int mvar3 = 1;
	
	int mvar4 = 1;
	
	int mvar5 = 1;
	
	int div5 = func1(mvar1, mvar2, mvar3, mvar4, mvar5)/5;
	
	return div5;
	
	}

a. How does the calling function “func2” pass the values to the called function “func1”?

Through registers as shown in figure below

![Disassembly screenshot](https://github.com/vigoren-uw/embsys310/blob/main/assignment04/func1_func2_a.jpg)

b. What extra code did the compiler generate before calling the function “func1” with the multiple arguments?

There is an addition of stack pointer referene as shown in figure below

![Disassembly screenshot](https://github.com/vigoren-uw/embsys310/blob/main/assignment04/func1_func2_b.jpg)

c. What extra code did the compiler generate inside the called function “funct1” with the multiple list of arguments?

There is an addition of a push and stack pointer referene as shown in figure below

![Disassembly screenshot](https://github.com/vigoren-uw/embsys310/blob/main/assignment04/func1_func2_c.jpg)

d. Any other observations?

None I could identify. 



