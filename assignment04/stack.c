#include "stack.h"
#define QUEUE_SIZE 3

// Requirement i and ii - fixed size int array to store stack
int QueueStore[QUEUE_SIZE];

// Pointers to stack elements for push and pop action
int* pushPtr;
int* popPtr;

// Requirement iii - Initialize internals of the queue
void queue_init(void)
{
    // Initialize pointers to 0
    pushPtr = 0;
    popPtr = 0;
    
    // fills QueueStore array with 0s
    for(int i=0; i<QUEUE_SIZE; i++)
    {
      QueueStore[i] = 0;
    }
}

// Requirement iv - Push data to stack
// If stack is full return -1 error to main
// Otherwise return 0, success
int queue_push(int data)
{
    // requirement vii: stack_full returns 1
    if (stack_full() == 1)
    {
      return -1;
    }
    
    // if pushPtr and popPtr are 0 from initialization, set to the address of the first QueueStore element
    if (popPtr == 0 && pushPtr == 0)
    {
      pushPtr = &QueueStore[0];  
      popPtr = &QueueStore[0]; 
    }    
    
    else
    {
      pushPtr++;
      popPtr++;
    }
    
    *pushPtr = data;
    return 0;
}

// Requirement v - Pop data from stack
// If stack is empty return -1 error to main
// Otherwise return 0, success
int queue_pop(int* data)
{   
    // requirement vi - stack_empty return 1
    if (stack_empty() == 1)
    {
      return -1;
    }
    
    else
    {
      *data = *popPtr;
      popPtr--;
      pushPtr--;
      // -- for popPtr and pushPtr since queue_pop pops element off stack 
    }
    
    return 0;
}

// requirement vii - pulled from queue_push and made into a fuction, stack_full return 1
int stack_full(void)
{
    if (pushPtr == &QueueStore[QUEUE_SIZE-1])
    {
      return 1;
    }
    
    return 0;
}
        
// requirement vi - pulled from queue_pop and made into a fuction, stack_empty return 1
int stack_empty(void)
{
    if (popPtr == 0 || popPtr == &QueueStore[-1])
    {
        // stack is empty !! still only initialized values, not puts yet to change to q{0]
        return 1;
    }
    
    return 0;
    
}
