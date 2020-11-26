// swap program based on guidance from 
// https://stackoverflow.com/questions/8403447/swapping-pointers-in-c-char-int

#include<assert.h>
void swapCharsAsm(char* a, char* b);

//  PUBLIC swapCharsAsm
   
// void swapCharsAsm(char* a, char* b);

int main()
{

char c = 'e';
char d = 'f';

swapCharsAsm(&c, &d); 

assert(c == 'f');
assert(d == 'e');

return(0);

}

void swapCharsAsm(char* a, char* b) 
{

asm("LDRB R2, [R0]"); // loads value at address [R0] (char a) into R2 
asm("LDRB R3, [R1]"); // loads value at address [R1] (char b) into R3 
asm("STRB R3, [R0]"); // stores R3 (char b) in address [R0] (char a)
asm("STRB R2, [R1]"); // stores R2 (char a) in address [R1] (char b) 
          
return;
}


/*
void swapCharsAsm(char* a, char* b) {
    char temp = *a;
    *a = *b;
    *b = temp;
}
*/
