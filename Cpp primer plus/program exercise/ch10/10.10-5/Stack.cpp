#include<iostream>
#include"Stack.h"

Stack::Stack()
{
 m_tops=0;
}
Stack::Stack(const Item*ar,int n)
{
 int x;
 if (n>ISIZE)
   std::cout<<"The max size for stack is "<<ISIZE<<".The exceeding contents will be aborted.\n";
 for (x=0;x<n&&x<ISIZE;x++)
   m_items[x]=ar[x];
 m_tops=x;
}
bool Stack::IsEmpty()
{
  return m_tops==0;
}
bool Stack::IsFull()
{
  return m_tops==ISIZE;
}
bool Stack::Push(const Item&item)
{
 using std::cout;
 if (IsFull())
 {
  cout<<"The stack is already full.\n";
  return false;
  }
 else
  m_items[m_tops++]=item;
return true;
}
bool Stack::Pop(Item&item)
{
 if (IsEmpty())
 {
  std::cout<<"The stack is already empty.Unable to pop.\n";
  return false;
  }
 else 
  item=m_items[--m_tops];
 return true;
}
   
