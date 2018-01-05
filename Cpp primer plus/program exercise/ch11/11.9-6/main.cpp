#include<iostream>
#include"Stonewt.h"

int main(void)
{
  using std::cout;
  Stonewt min,max;
  int res=0;
  Stonewt ar[6]={18,28,38};
  for (int x=3;x<6;x++)
    ar[x]=x+6;
  min=max=ar[0];
  for (int x=0;x<6;x++)
  {
   if (ar[x]<min)
     min=ar[x];
   if (ar[x]>max)
     max=ar[x];
   if (ar[x]>=Stonewt(11))
     res++;
   cout<<"#"<<x<<":"<<ar[x]<<"\n";
   }
  cout<<"max:"<<max;
  cout<<"min:"<<min;
  cout<<"res:"<<res<<std::endl;
  return 0;
}
  
