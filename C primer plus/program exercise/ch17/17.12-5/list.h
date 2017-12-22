#ifndef _stack_h
#define _stack_h
#include<stdbool.h>

#define MAXSTACK 100

typedef char* ITEM;
typedef struct stack{
   ITEM items[MAXSTACK];
   int top;
      }STACK;

void Initialize(STACK*ps);
bool StackIsEmpty(STACK*ps);
bool StackIsFull(STACK*ps);
bool Push(STACK*ps,ITEM item);
bool Pop(STACK*ps,ITEM* pi);

#endif
