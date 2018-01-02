#include<iostream>
#include"Sales.h"

namespace SALES
{
  Sales::Sales(const double ar[],int n)
  {
  int x;   
   for (x=0;x<n;x++)
    {
     sales[x]=ar[x];
     if (x==0)
       min=max=sales[0];
     average+=sales[x];
     if (sales[x]>max)
      max=sales[x];
     if (sales[x]<min)
      min=sales[x];
     }
     average/=x;
   while (x<QUARTERS)
    sales[x++]=0;
  }
  Sales::Sales()
  {
   for (int x=0;x<QUARTERS;x++)
     sales[x]=0;
   min=max=average=0;
  }
   void Sales::setSales(void) 
   {
    using std::cout;
    using std::cin;
    using std::endl;    
    int x;
    double ar[QUARTERS];
    for (x=0;x<QUARTERS;x++)
     {
     cout<<"Please enter for sales #"<<x+1<<":";
     if (!(cin>>ar[x]))
      {
       cin.clear();
       while (cin.get()!='\n');
       break;
      }
     }
    for (int i=x;i<QUARTERS;i++)
     ar[i]=0;   
     *this=Sales(ar,x);
     return;
    }          
   void Sales::showSales(void) const
   {
    using std::cout;
    using std::cin;
    using std::endl;
    for (int x=0;x<QUARTERS;x++)
      cout<<"#"<<x+1<<":"<<sales[x]<<endl;
    cout<<"average="<<average<<endl;
    cout<<"min="<<min<<endl;
    cout<<"max="<<max<<endl;
    return;
   }
}
