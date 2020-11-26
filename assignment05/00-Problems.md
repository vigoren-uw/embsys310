

Problems:

1. Create a function in “C” that allows swapping of two pointers.

a. Explain what the “main” function does in order to setup the input arguments prior to calling the swap_pointer() function?
 
	"main" puts the variables on the stack
   	int x = 42;
  	int y = 17;
	int* xp = &x;
  	int* yp = &y;

b. What are the values in R0 & R1 when swap_pointer() is called?

	R0: holds the memory location of the pointer xp pointing to x
	R1: holds the memory location of the pointer yp pointing to y

c. Share a screen shot of the local variables inside of “main” after the function swap_pointer() returns showing the values of the pointers and what they are pointing to (similar to the picture below).

Screen shot below and in 01-stack_pointer-after_call.JPG:
![Disassembly screenshot](https://github.com/vigoren-uw/embsys310/blob/main/assignment05/01-stack_pointer-after_call.JPG)

2. Create a new file divAsm.s and add the file to the same HelloWorld project above.

d. Add a comment for every statement in your assembly function code.

	- Fuction and all comments are in file 02-divAsm-divAsm-Copy.s

e. Invoke divAsm() inside of your main function in main.c

	- Fuction called in 02-divAsm-main-Copy.c

f. Run your program on the board and capture a snapshot image of the output from TeraTerm showing the result of the divAsm.

Screen shot below and in 02-divAsm-tera_term_output.JPG:
![Disassembly screenshot](https://github.com/vigoren-uw/embsys310/blob/main/assignment05/02-divAsm-tera_term_output.JPG)

3. Implement a swap function in assembly and call it “swapCharsAsm”:

b. Add a comment for every statement in your assembly function code.

	- Fuction and all comments are in 03-swapCharsAsm-main-Copy.c

Screenshot before and after below and correspondingly in 03-swapCharsAsm_before_call.JPG and 03-swapCharsAsm_after_call.JPG:
![Disassembly screenshot](https://github.com/vigoren-uw/embsys310/blob/main/assignment05/03-swapCharsAsm_before_call.JPG)
![Disassembly screenshot](https://github.com/vigoren-uw/embsys310/blob/main/assignment05/03-swapCharsAsm_after_call.JPG)



