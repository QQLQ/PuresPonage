#include<iostream>
#include"head.h"

namespace SALES
{
   void setSales(Sales &s,const double ar[],int n)
   {
    if (n==0)
     {
      std::cout<<"No data\n";
      return;
     }
    s.min=s.max=ar[0];
    for (int x=0;x<n;x++)
    {
     s.sales[x]=ar[x];
     s.average+=ar[x];
     if (ar[x]>s.max)
      s.max=ar[x];
     if (ar[x]<s.min)
      s.min=ar[x];
    }
    s.average/=n;
    return;
   }
   void setSales(Sales &s) //Both setsales function must be initialized to zero in whole
   {
    using std::cout;
    using std::cin;
    using std::endl;
    int x;
    for (x=0;x<QUARTERS;x++)
     {
     cout<<"Please enter for sales #"<<x+1<<":";
     if (!(cin>>s.sales[x]))
       break;
      if (x==0)
       s.min=s.max=s.sales[0];
     s.average+=s.sales[x];
     if (s.sales[x]>s.max)
      s.max=s.sales[x];
     if (s.sales[x]<s.min)
      s.min=s.sales[x];
     }
     if (cin.fail())
      {
       cin.clear();
       while (cin.get()!='\n');
      }
     s.average/=x;
     return;
    }
     
        
   void showSales(const Sales &s)
   {
    using std::cout;
    using std::cin;
    using std::endl;
    for (int x=0;x<QUARTERS;x++)
      cout<<"#"<<x+1<<":"<<s.sales[x]<<endl;
    cout<<"average="<<s.average<<endl;
    cout<<"min="<<s.min<<endl;
    cout<<"max="<<s.max<<endl;
    return;
   }
}
