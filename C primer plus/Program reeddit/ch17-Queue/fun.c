#include"queue.h"
#include<stdio.h>
#include<stdlib.h>
static void CopyToNode(NODE* pn,ITEM temp);
static void CopyToItem(NODE* pn,ITEM*pi);

void Initialize(QUEUE* pq)
	{
  pq->front=pq->rear=NULL;
  pq->size=0;
return;
}

bool QueueIsFull(QUEUE* pq)
{
  if (pq->size==MAXSIZE)
    return true;
  else 
    return false;
} 

bool QueueIsEmpty(QUEUE* pq)
{
  if (pq->size==0)
    return true;
  else 
    return false;
}

int QueueItemCount(QUEUE* pq)
{
  return pq->size;
}

bool AddItem(QUEUE* pq,ITEM temp)
{
   NODE* pnew;

   if (true==QueueIsFull(pq))
     return false;

   pnew=(NODE*)malloc(sizeof(NODE));
   if (pnew==NULL)
   {
    fprintf(stderr,"Problem allocating memory\n");
    exit(1);
    }

   pnew->next=NULL;
   CopyToNode(pnew,temp);
   if ( QueueIsEmpty(pq))
     pq->front=pnew;
   else 
     pq->rear->next=pnew;
   pq->rear=pnew;
   pq->size++;
return true;
}    

bool DeleteTheQueue(QUEUE* pq,ITEM* temp)
{
 NODE* pt;

 if (QueueIsEmpty(pq))
   {
    fprintf(stderr,"No data\n");
    return false;
   }
  CopyToItem(pq->front,temp);
  *temp=pq->front->item;
  pt=pq->front;
  pq->front=pq->front->next;
  free(pt);
  pq->size--;
  if (pq->size==0)
    pq->rear=NULL;
return true;
}

void EmptyTheQueue(QUEUE* pq)
{
  NODE* scan;
  while (pq->size!=0)
  {
   scan=pq->front->next;
   free(pq->front);
   pq->front=scan;
   pq->size--;
   }
   pq->rear=NULL;
return;
}


void Traverse(QUEUE* pq,void (*pfun)(ITEM item))
{
  int i;
  NODE* scan;
  if (true==QueueIsEmpty(pq)){
   fprintf(stderr,"No data\n");
   return;
   }
   scan=pq->front;
  for (i=0;i<pq->size;i++){
   pfun(scan->item);
   scan=scan->next;
#ifdef TEST
   printf("I=%d",i);
#endif
   }

return;
}

static void CopyToNode(NODE* pn,ITEM temp)
{
   pn->item=temp;
return;
}

static void CopyToItem(NODE* pn,ITEM*pi)
{
   *pi=pn->item;
return;
}
