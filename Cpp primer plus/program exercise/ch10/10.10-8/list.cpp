#include<iostream>
#include"list.h"

list::list(const ITEM& item)
{
 start=new NODE;
 start->item=item;
 start->next=NULL;
 nums=1;
}
list::list()
{
 start=NULL;
 nums=0;
}
void list::dnode(NODE*pn)
{
  if (pn!=NULL)
   dnode(pn->next);
  else 
   return;
  delete pn;
  return;
}
list::~list()
{
 NODE*pn=start;
 dnode(pn);
 std::cout<<"Terminated!(sunglass)\n";
}
bool list::add(ITEM&item)
{
 if (isfull())
  {
   std::cout<<"The list is already full.\n";
   return false;
  }
 else
  {
  NODE* pn=NULL;
  NODE* temp=start;
  while (temp!=NULL)
    {
     pn=temp;
     temp=temp->next;
    }
  if (pn==NULL)
   {
    start=new NODE;
    start->item=item;
    start->next=NULL;
    nums++;
    }
  else
   {
    pn->next=new NODE;
    pn->next->item=item;
    pn->next->next=NULL;
    nums++;
   }
  }
return true;
}     
bool list::isempty(void)
{
  return start==NULL;
}
bool list::isfull(void)
{
  return nums==MAXSIZE;
}
void list::visit(void (*pf)(ITEM&))
{
 NODE*pn=start;
 while (pn!=NULL)
  {
   pf(pn->item);
   pn=pn->next;
  }
}
