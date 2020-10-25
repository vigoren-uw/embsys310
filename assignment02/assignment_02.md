Aaron Vigoren

EMBSYS 310 - AU20

ASSIGNMENT 02


Observe and answer:
Create a new IAR project with the following program in a main.c file, then follow the questions below:

	int main() {
	int counter = 0;
	counter ++;
	counter ++;
	counter ++;
	counter ++;
	counter ++;
	counter ++;
	counter ++;
	return 0;}

1. Inject 0x7FFFFFFF for the “counter” value in the variable window, then step thru the program only once to increment “counter”.

	a) What is the value of the “counter” from the “Locals” window?
	
		0x80000000
		
	b) What is the value of the “counter” in the “Registers” window?
	
		0x80000000
		
	c) Please note down if the N and/or V flags are set in the APSR register. And explain why.
	
		0x80000000 == 0b10000000000000000000000000000000
		N (negative condition flag) is set to 1 because the sign_bit is 1 representing a negative number 
		V (overflow condition flag) is set to 1 because the numeric value jumps from 2147483647 to -2147483648

2. If your write all Fs (0XFFFFFFFF) in the Register value for “counter” then step thru the program once to increment “counter”

	a) What happens to the value of “counter” in the “Locals” window?
	
		0xFFFFFFFF == 0b11111111111111111111111111111111
		Incrementing by 1 changed the value of "couter" to now
		0x00000000 == 0b00000000000000000000000000000000
		
	b) Please note down if the N and/or V flags are set in the APSR register. And explain why.
	
		N is set to 0 because the sign_bit is 0 representing a positive number
		V is set to 0 because the number logically goes from -1 to 0

3. Change the “counter” variable type in your code to “unsigned int”. Inject the values “0x7FFFFFFF” then step thru the program to increment the “counter” once:

	a) What is the value of “counter” in the “Locals” window after incrementing for each value?
	
		0x80000000
		
	b) Please note down if the N and/or V flags are set in the APSR register. And explain why.
	
		0x80000000 == 0b10000000000000000000000000000000
		N is still set to 1 because the sign_bit/MSB is 1 
		V is set to 1 because the numeric value jumps from 2147483647 to 2147483648

4. Change the “counter” variable type in your code to “unsigned”. Inject the values “0xFFFFFFFF” then step thru the program to increment the “counter” once:

	a) What is the value of “counter” in the “Locals” window after incrementing for each value?
	
		0xFFFFFFFF == 0b11111111111111111111111111111111
		Incrementing by 1 changed the value of "couter" to now
		0x00000000 == 0b00000000000000000000000000000000
		
	b) Please note down if the N and/or V flags are set in the APSR register. And explain why.
	
		N is still set to 0 because the sign_bit/MSB is 0 
		V is set to 0 because the number logically goes from -1 to 0

5. Move the “counter’ variable outside of main (at the top of the file):

	a) What is the scope of the variable “counter”?
	
		Global variable 
		
	b) Is it still visible in the “Locals” view?
	
		No
		
	c) In which window view can we track “counter” now?
	
		In the "Watch1" window
		
	d) What is the address of the “counter” variable in memory?
	
		0x20000000

6. Change the source code to the following, then run the program in the simulator:

	int counter = 0x0;
	int main() {
	int *p_int = (int *)0x20000000;
	++(*p_int);
	++(*p_int);
	++(*p_int);
	counter ++;
	return 0;}

	a) What is the value of “counter” at the end of the program (halting at the return 0 statement)
	
		0x00000004
		
	b) Explain why the counter value has changed?
	
	
		The counter value changed because the value at pointer p_int that was pointing to the memory address of "couter" was being incremented 
		int *p_int = (int *)0x20000000;
		++(*p_int);

7. Change the setting of IAR to run the same program on the evaluation board:

	a) What is the address where “counter” is stored?
	
		0x20000000
		
	b) Is the “counter” variable stored in RAM or ROM?
	
		RAM - 0x20000000 is the first SRAM address 
		
	c) What is the value of “counter” at the end of the program (halting at the return 0 statement)
	
		0x00000004
		
