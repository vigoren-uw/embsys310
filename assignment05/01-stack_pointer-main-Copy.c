// reference https://stackoverflow.com/questions/8403447/swapping-pointers-in-c-char-int

#include<assert.h>
void swap_pointer(int** a, int** b); 

int main()
{
    int x = 42;
    int y = 17;
    int* xp = &x;
    int* yp = &y;
    swap_pointer(&xp, &yp);
    assert(xp == &y);
    assert(yp == &x);
    assert(x == 42);
    assert(y == 17);
    
    return 0;
}

void swap_pointer(int** a, int** b) 
{
    int* temp = *a;
    *a = *b;
    *b = temp;
    assert(**a == 17);
    assert(**b == 42);
}
