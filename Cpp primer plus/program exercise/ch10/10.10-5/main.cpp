#include<iostream>
#include"Stack.h"

int main(void)
{
  using namespace std;
  double total=0;
  Item temp;
  Stack test;
  char ch;
  cout<<"Option:a) add  b) delete  c) show   q)quit\n";
  cout<<"Please enter your choice:";
  while (cin>>ch&&ch!='q')
  {
   while (cin.get()!='\n');
   switch(ch)
   {
    case 'a':cout<<"Please enter the name:";
             cin.getline(temp.fullname,FSIZE);
             cout<<"Please enter the payment:";
             while (!(cin>>temp.payment))
             {
              cin.clear();
              while (cin.get()!='\n');
              cout<<"Invalid input ,enter again:";
             }
             while (cin.get()!='\n');
             test.Push(temp);
             break;
    case 'b':if (test.Pop(temp))
              total+=temp.payment; 
             break;
    case 'c':cout<<"Money in total:"<<total<<".\n";
             break;
    default: cout<<"Invalid input,enter again";
             continue;
    }
    cout<<"Enter your choice please:";
  }
  cout<<"Done!";
  return 0;
}
