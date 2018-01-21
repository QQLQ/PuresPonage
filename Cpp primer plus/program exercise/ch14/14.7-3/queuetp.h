#ifndef QUEUETP_H_
#define QUEUETP_H_

#include<iostream>

using std::cout;
using std::cin;
using std::endl;


template<typename Type>
class QueueTP
{
private:
  struct Node{Type item;Node* next;};
  Node* front;
  Node* rear;
  int items;
  int MAXSIZE;
public:
  QueueTP():MAXSIZE(3){front=rear=NULL;items=0;}
  QueueTP(int titems,int MSIZE=3);
  QueueTP(Type*ar,int titems,int MSIZE=3);
  ~QueueTP();
  QueueTP(const QueueTP<Type> & rt)=delete;
  QueueTP<Type>& operator=(const QueueTP<Type> & rt)=delete;
  bool isempty();
  bool isfull();
  bool additem(const Type&);
  bool deleteitem(Type&);
  int count();
  Type& operator[](int n);
  const Type& show(int n);
};
template<typename Type>
QueueTP<Type>::QueueTP(int titems,int MSIZE):MAXSIZE(MSIZE)
{
 int i;
 Node*temp;
 if (titems>0)
  {
   for (i=0;i<titems&&i<MAXSIZE;i++)
    {
     if (front==NULL)
       {
        front=new Node;
        rear=front;
       }
     else
       {
       rear->next=new Node;
       rear=rear->next;
       }
    }
    if (i>MSIZE)
     cout<<"Only "<<i<<" items have been added due to reaching maxsize.\n";
   items=i;
  }
 else 
  {
   items=0;
   front=rear=NULL;
  }
}

template<typename Type>
QueueTP<Type>::QueueTP(Type*ar,int titems,int MSIZE):MAXSIZE(MSIZE)
{
 int i;
 for (i=0;i<titems&&i<MAXSIZE;i++)
  {
   if (isempty())
   {
     front=new Node(ar[i],NULL);
     rear=front;
   }
   else
   {
    rear->next=new Node(ar[i],NULL);
    rear=rear->next;
   }
  }
 if (i<titems)
 {
   cout<<"Reached Maxsize,only "<<titems<<" items joined the queue."<<endl;
 }

   items=i;
}  
  
template<typename Type>
QueueTP<Type>::~QueueTP()
{
 int i=0;
 Node* temp;
 while (front)
 {
  temp=front;
  front=front->next;
  delete temp;
  i++;
 }
 //cout<<"DESTROYED:"<<i<<endl;  //test it if you want
}

template<typename Type>
bool QueueTP<Type>::isempty()
{
  return items==0;
}
template<typename Type>
bool QueueTP<Type>::isfull()
{
  return items==MAXSIZE;
}
template<typename Type>
bool QueueTP<Type>::additem(const Type&rt)
{
 if (isfull())
   return false;
   
 if (front==NULL)
  {
   front=new Node(rt,NULL);
   rear=front;
  }
 else
  {
   rear->next=new Node(rt,NULL);    
   rear=rear->next;
  }
 items++;
 return true;
}

template<typename Type>
bool QueueTP<Type>::deleteitem(Type&rt)
{
 if (isempty())
  return false;
 rt=front->item;
 Node* temp;
 temp=front;
 front=front->next;
 delete temp;
 items--;
}
template<typename Type>
int QueueTP<Type>::count()
{
 return items;
}

template<typename Type>
Type& QueueTP<Type>::operator[](int n)
{
Type* screwed=new Type;   //Ignore this.I may know how to deal with this after cp 15

 if (n>=items||n<0)
 {
   cout<<"No matched data"<<endl;
   return *screwed;  //This is definately memorary leakage, serious. No shit
  }
  
 int i;
 Node*target=front;
 for (i=0;i<n;i++)
   target=target->next;
 return target->item;
}


template<typename Type>
const Type& QueueTP<Type>::show(int n)
{
 Type* screwed=new Type;  //Awkward
 if (n>items||n<1||isempty())
 {
   cout<<"No matched data"<<endl;
   return *screwed;   //Same,i know.
  }
 int i;
 Node*target=front;
 for (i=1;i<n;i++)
   target=target->next;
 return target->item;
}

#endif

