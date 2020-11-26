

Problems:

1. Create a function in “C” that allows swapping of two pointers.
a. Explain what the “main” function does in order to setup the input arguments prior to calling the swap_pointer() function?
b. What are the values in R0 & R1 when swap_pointer() is called?
c. Share a screen shot of the local variables inside of “main” after the function swap_pointer() returns showing the values of the pointers and what they are pointing to (similar to the picture below).


2. Create a new file divAsm.s and add the file to the same HelloWorld project above.

d. Add a comment for every statement in your assembly function code.
	- fuction in file "02 - divAsm - divAsm - Copy.s"

e. Invoke divAsm() inside of your main function in main.c
	- fuction called in "02 - divAsm - main - Copy.c"

f. Run your program on the board and capture a snapshot image of the output from TeraTerm showing the result of the divAsm.

![Disassembly screenshot](https://github.com/vigoren-uw/embsys310/blob/main/assignment05/'02 - divAsm - tera_term_output.JPG')

3. Implement a swap function in assembly and call it “swapCharsAsm”:
a. It takes as input two variables of char data type each and swaps the two chars.
b. Add a comment for every statement in your assembly function code.
c. Bonus: Return 0 if the two chars are identical; otherwise, return 1.
4. Bonus: Implement the swap_pointer() function from #1 above in assembly and call it swapPointersAsm().
a. Add a comment for every statement in your assembly function code.
b. Invoke swapPointersAsm() from your main function main.c
c. Run your program on the board and capture a snapshot image of the output from TeraTerm showing the result of the swapPointersAsm() subroutine.








![Disassembly screenshot](https://github.com/vigoren-uw/embsys310/blob/main/assignment04/JPG_figures/gpioa_WITH_bitbanding1.JPG)
![Disassembly screenshot](https://github.com/vigoren-uw/embsys310/blob/main/assignment04/JPG_figures/gpioa_WITH_bitbanding2.JPG)

b) What were the instructions produced when writing to the RCC_AHB2ENR (correction, not "GPIOx_ODR") without using bit-banding?

Instructions in disassembly figures below. Blue box after immediately after main is when RCC_AHB2ENR is invoked. Note, in red, we have "0x4242'0980" with bit-banding and "RCC_AHB2ENR" without bit-banding in the instructions.

![Disassembly screenshot](https://github.com/vigoren-uw/embsys310/blob/main/assignment04/JPG_figures/gpioa_NO_bitbanding1.JPG)
![Disassembly screenshot](https://github.com/vigoren-uw/embsys310/blob/main/assignment04/JPG_figures/gpioa_NO_bitbanding2.JPG)


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

![Disassembly screenshot](https://github.com/vigoren-uw/embsys310/blob/main/assignment04/JPG_figures/func1_func2_a.jpg)

b. What extra code did the compiler generate before calling the function “func1” with the multiple arguments?

There is an addition of stack pointer referene as shown in figure below

![Disassembly screenshot](https://github.com/vigoren-uw/embsys310/blob/main/assignment04/JPG_figures/func1_func2_b.jpg)

c. What extra code did the compiler generate inside the called function “funct1” with the multiple list of arguments?

There is an addition of a push and stack pointer referene as shown in figure below

![Disassembly screenshot](https://github.com/vigoren-uw/embsys310/blob/main/assignment04/JPG_figures/func1_func2_c.jpg)

d. Any other observations?

None I could identify. 



