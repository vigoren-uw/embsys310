#include<assert.h>
#include"stack.h"
#include"stack.c"

int main()
{
    int result1;
    int result2;
    int result3;
    int testInt;
    
    // *******************************************************************
    // Test1: Retrieve item from an empty stack
    // *******************************************************************
    
    // Arrange:
    result1 = 77;
    testInt = 77;
    queue_init();
    
    // Act:
    result1 = queue_pop(&testInt);
      
    // Assert:
    assert(-1 == result1); // Planned failure
    assert(77 == testInt);
    
    // *******************************************************************
    // Test2: Successfully retrieve an item from the stack
    // *******************************************************************
   
    // Arrange:
    result1 = 77;
    result2 = 77;
    testInt = 77;
    queue_init();
    
    // Act:
    result1 = queue_push(1);
    result2 = queue_pop(&testInt);
    
    // Assert:
    assert(0 == result1);
    assert(0 == result2);
    assert(1 == testInt);
    
    // *******************************************************************
    // Test3: Fill stack, then get all items.
    // *******************************************************************
    
    // Arrange:
    result1 = 77;
    result2 = 77;
    result3 = 77;
    testInt = 77;
    queue_init();
    
    // Act:
    result1 = queue_push(1);
    result2 = queue_push(2);
    result3 = queue_push(3);                                    
    
    // Assert:
    
    assert(0 == result1);
    assert(0 == result2);
    assert(0 == result3);
    
    assert(0 == queue_pop(&testInt));
    assert(3 == testInt);

    assert(0 == queue_pop(&testInt));
    assert(2 == testInt);

    assert(0 == queue_pop(&testInt));
    assert(1 == testInt);

    
    // *******************************************************************
    // Test4: Fill stack, then put one more item, should fail
    // *******************************************************************
    
    // Arrange:
    testInt = 77;
    queue_init();
    
    // Act:
    queue_push(1);
    queue_push(2);
    queue_push(3);
    
    // Assert:
    assert(-1 == queue_push(4)); // Planned failure

    assert(0 == queue_pop(&testInt));
    assert(3 == testInt);

    assert(0 == queue_pop(&testInt));
    assert(2 == testInt);

    assert(0 == queue_pop(&testInt));
    assert(1 == testInt);

    // ***********************************************************************
    // Test5: Fill stack, retrieve one item, then add item, then retieve all
    // ***********************************************************************
    
    // Arrange:
    testInt = 77;
    queue_init();
    
    // Act:
    queue_push(1);
    queue_push(2);
    queue_push(3);
    
    // Assert:
    assert(0 == queue_pop(&testInt));
    assert(3 == testInt);

    assert(0 == queue_push(4));

    assert(0 == queue_pop(&testInt));
    assert(4 == testInt);

    assert(0 == queue_pop(&testInt));
    assert(2 == testInt);

    assert(0 == queue_pop(&testInt));
    assert(1 == testInt);

    // ***********************************************************************
    // Test6: 
    // 1. Fill stack and retrieve all items. 
    // 2. Do it twice in a row.
    // 3. Test queue_pop now with the queue being empty
    // ***********************************************************************
    
    // Arrange:
    testInt = 77;
    queue_init();
    
    // Act:
    queue_push(1);
    queue_push(2);
    queue_push(3);
    
    // Assert:
    assert(0 == queue_pop(&testInt));
    assert(3 == testInt);

    assert(0 == queue_pop(&testInt));
    assert(2 == testInt);

    assert(0 == queue_pop(&testInt));
    assert(1 == testInt);

    // Act2:
    assert(0 == queue_push(4));
    assert(0 == queue_push(5));
    assert(0 == queue_push(6));
        
    // Assert2:
    assert(0 == queue_pop(&testInt));
    assert(6 == testInt);
   
    assert(0 == queue_pop(&testInt));
    assert(5 == testInt);

    assert(0 == queue_pop(&testInt));
    assert(4 == testInt);
    
    // test now when the queue is empty
    // Assert3:
    assert(-1 == queue_pop(&testInt)); // Planned failure

    return 0;
}
