#include<iostream>
#include<cstring>
#include"Golf.h"

Golf::Golf(const char*fn,int hc)
{
 strcpy(fullname,fn);
 if (hc<0)
  {
   std::cout<<"The handicap must not be negative,handicap set to 0\n";
   handicap=0;
  }
 else 
  handicap=hc;
  strcpy(fullname,fn);
}
Golf::Golf()
{
  strcpy(fullname,"Error_name");
  handicap=0;
}
void Golf::Setgolf(void)
{
  using std::cout;
  using std::cin;
  char name[LEN];
  cout<<"Please enter name:";
  cin.getline(name,LEN);
  cout<<"Now please enter handicap value:";
  int hc;
  while (!(cin>>hc))
   {
     cin.clear();
     while (cin.get()!='\n');
     cout<<"Invalid input,reenter please:";
   }
   while (cin.get()!='\n');
   *this=Golf(name,hc);
   return;
}
void Golf::Handicap(int hc)
{

   handicap=hc;
   return;
}
void Golf::Showgolf(void) const
{
 std::cout<<"Name: "<<fullname<<" hc:"<<handicap<<"\n";
 return;
}
