#ifndef _QUEUE_H
#define _QUEUE_H
#include<stdbool.h>
#define MAXSIZE 10
#define NSIZE 21
typedef struct {
   long arrive;
   int processtime;
    } ITEM;

typedef struct node{
    ITEM item;
    struct node* next;
      }NODE;

typedef struct {
   NODE* front;
   NODE* rear;
   int size;
      } QUEUE;

void Initialize(QUEUE* pq);

bool QueueIsFull(QUEUE* pq);

bool QueueIsEmpty(QUEUE* pq);

bool AddItem(QUEUE* pq,ITEM temp);

bool DeleteTheQueue(QUEUE* pq,ITEM* temp);

void EmptyTheQueue(QUEUE* pq);

int QueueItemCount(QUEUE* pq);

void Traverse(QUEUE* pq,void (*pfun)(ITEM item));

#endif
