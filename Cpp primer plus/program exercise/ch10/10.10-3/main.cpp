#include<iostream>
#include"Golf.h"

int main(void)
{
  using std::cout;
  using std::cin;
  char name[40];
  cout<<"please enter name:";
  cin.getline(name,40);
  cout<<"Please enter the value for handicap:";
  int hc;
  while (!(cin>>hc))
   {
     cin.clear();
     while (cin.get()!='\n');
     cout<<"Invalid input,reenter please:";
   }
   while (cin.get()!='\n');
   Golf test1(name,hc);
   test1.Showgolf();
   Golf test2;
   test2.Showgolf();
   test2.Setgolf();
   test2.Showgolf();
   cout<<"Please enter the new value for handicap:";
   while (!(cin>>hc))
   {
     cin.clear();
     while (cin.get()!='\n');
     cout<<"Invalid input,reenter please:";
   }
   test2.Handicap(hc);
   test2.Showgolf();
   return 0;
}
