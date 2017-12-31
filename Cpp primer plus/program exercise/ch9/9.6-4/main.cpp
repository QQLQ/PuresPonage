#include<iostream>
#include"head.h"

int main(void)
{
  using std::cout;
  using std::cin;
  using std::endl;
  double ar[SALES::QUARTERS];
  int x;
  SALES::Sales him{},her{};
  cout<<"For him:"<<endl;
  for (x=0;x<SALES::QUARTERS;x++)
   {
    cout<<"Please enter for sales #"<<x+1<<":";
    if (!(cin>>ar[x]))
      break;
   }
   if(cin.fail())
    {
     cin.clear();
     while (cin.get()!='\n');
    }
   SALES::setSales(him,ar,x);
   cout<<"For her:"<<endl;
   SALES::setSales(her);
   cout<<"Show him"<<endl;
   SALES::showSales(him);
   cout<<"Show her"<<endl;
   SALES::showSales(her);
   return 0;
}
