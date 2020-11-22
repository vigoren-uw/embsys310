/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __QUEUE_H__
#define __QUEUE_H__

void queue_init(void);
int queue_push(int data);
int queue_pop(int* data);
int stack_full(void);
int stack_empty(void);


#endif
