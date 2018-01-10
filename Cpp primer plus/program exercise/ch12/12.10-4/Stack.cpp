#include<iostream>
#include"Stack.h"

Stack::Stack(int n)
{
  std::cout<<"constructor\n";
  if (n<1)
  {
   std::cout<<"The size must be bigger than 0.Set to "<<MAX<<std::endl;
   n=MAX;
  }
  pitems=new Item[n];
  size=n;
  top=0;
}  
Stack::Stack(const Stack& st)
{
  std::cout<<"copy constructor\n";

  size=st.size;
  pitems=new Item[st.size];
  for (int i=0;i<st.top;i++)
    pitems[i]=st.pitems[i];
  top=st.top;
}
Stack::~Stack()
{
  std::cout<<"destructor\n";

  delete []pitems;
}
bool Stack::isempty() const
{
 return top==0;
}
bool Stack::isfull() const
{
 return top>=size;
}
bool Stack::push(const Item& item)
{
  if (isfull())
  {
    std::cout<<"The stack is already full.\n";
    return false;
  }
  pitems[top++]=item;
  return true;
} 
bool Stack::pop(Item&item)
{
  if (isempty())
  {
   std::cout<<"The stack is empty currently.\n";
   return false;
  }
  item=pitems[--top];
  return true;
}
Stack& Stack::operator=(const Stack&st)
{
  std::cout<<"= function\n";
  if (this==&st)
    return *this;
  delete []pitems;
  size=st.size;
  pitems=new Item[st.size];
  for (int i=0;i<st.top;i++)
    pitems[i]=st.pitems[i];
  top=st.top;
}
