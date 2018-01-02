#include<iostream>
#include"list.h"

void show(ITEM&);

int main(void)
{
  using namespace std;
  {
  list test;
  ITEM temp;
  char ch;
  cout<<"Option:a) add   b)check all items c)check list status  q)quit"<<endl;
  cout<<"Please enter choice:";
  while (cin.get(ch)&&ch!='q')
  {
   while (cin.get()!='\n');
   switch(ch)
   {
      case 'a':cout<<"Please enter the name:";
               cin.getline(temp.name,NSIZE);
               cout<<"Please enter the rank:";
               while (!(cin>>temp.rank))
                {
                 cin.clear();
                 while (cin.get()!='\n');
                 cout<<"Reenter please:";
                }
                while (cin.get()!='\n');
                test.add(temp);
                break;
      case 'b':test.visit(show);break;
      case 'c':if(test.isempty())  cout<<"The list is empty"<<endl; 
               else if(test.isfull()) cout<<"The list is reached max size"<<endl;
               else cout<<"The list is not full yet"<<endl;
               break;
      default:cout<<"Invalid input,enter again:";continue;
   }
   cout<<"Please enter your choice:";
  }
  }
  cout<<"Bye"<<endl;
  return 0;
}

void show(ITEM&item)
{
  std::cout<<"Name:"<<item.name<<" ,rank="<<item.rank<<std::endl;
}
