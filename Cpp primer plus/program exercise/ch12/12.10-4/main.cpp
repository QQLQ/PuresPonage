#include<iostream>
#include"Stack.h"

const int ASIZE=5;

int main(void)
{
  using namespace std;
  Item ar[ASIZE+1];
  Stack sar(ASIZE);
  if (sar.isempty())
    cout<<"Empty for sure.\n";
  if (sar.isempty())
    cout<<"Not full yet.\n";
  for (int i=0;i<ASIZE+1;i++)
   {
    ar[i]=i+1;
    sar.push(ar[i]);
   }

   Item temp;
   
  Stack sar2(sar);
  for (int i=0;i<ASIZE;i++)
    {
    if (!sar2.isempty()) sar2.pop(temp);
    cout<<temp<<endl;
    }
  Stack sar3;
  sar3=sar2;
  for (int i=0;i<ASIZE;i++)
    {
    sar3.pop(temp);
    if (!sar3.isempty())
     cout<<temp<<endl;
    }
  for (int i=0;i<ASIZE;i++)
    {
    if (!sar.isempty()) sar.pop(temp);
    cout<<temp<<endl;
    }
  
   
   return 0;
}
