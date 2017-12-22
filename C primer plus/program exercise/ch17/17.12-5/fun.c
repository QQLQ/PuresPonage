#include"list.h"
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

void Initialize(STACK*ps)
{
 ps->top=0;
return;
}

bool StackIsEmpty(STACK*ps)
{
 return ps->top==0;
}
bool StackIsFull(STACK*ps)
{
 return ps->top==MAXSTACK;
}

bool Push(STACK*ps,ITEM item)
{
 ITEM temp;
 if (StackIsFull(ps)==true)
  {
   printf("The stack is already full\n");
   return false;
  }
 temp=(ITEM)malloc(strlen(item)+1);
 strcpy(temp,item); 
 ps->items[ps->top]=temp;
 ps->top++;
return true;
}

bool Pop(STACK*ps,ITEM* pi)
{
   if(StackIsEmpty(ps))
    {
     printf("The stack is empty\n");
     return false;
    }
  ps->top--;
  *pi=(char*)malloc(strlen(ps->items[ps->top])+1);
  strcpy(*pi,ps->items[ps->top]);
  free(ps->items[ps->top]);
return false;
}
