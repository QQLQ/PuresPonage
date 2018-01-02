#include<iostream>
#include"Sales.h"
const int QUARTERS=4;

int main(void)
{
  using namespace std;
  using namespace SALES;
  double ar[QUARTERS];
  int x;
  Sales test1;
  test1.showSales();
  test1.setSales();
  test1.showSales();
  for (x=0;x<QUARTERS;x++)
  {  
   cout<<"Please enter number #"<<x+1<<":";
   if (!(cin>>ar[x]))
    {
     cin.clear();
     while (cin.get()!='\n');
     break;
     }
   }
   Sales test2(ar,x);
   test2.showSales();
   return 0;
}
