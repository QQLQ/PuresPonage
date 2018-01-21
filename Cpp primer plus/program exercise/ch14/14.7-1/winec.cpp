#include"winec.h"

using std::valarray;
using std::cout;
using std::cin;
using std::endl;

Wine::Wine():name("Noname"),years(-1)
{
 valarray<int> temp;
 PairArray ttemp(temp,temp);
 data=ttemp;
}

Wine::Wine(const char* l,int y,const int yt[],const int bot[]):name(l),years(y)
{
 valarray<int> temp1(yt,y);
 valarray<int> temp2(bot,y);
 Pair< valarray<int>,valarray<int> > ttemp(temp1,temp2); 
 data=ttemp;  
}

Wine::Wine(const char*l,int y):name(l),years(y)
{
 valarray<int> temp(y);
 PairArray ttemp(temp,temp);
 data=ttemp;
}
 
void Wine::GetBottles()
{
 cout<<"Enter "<<name<<" data for "<<years<<" year(s):"<<endl;
 for (int i=0;i<years;i++)
  {
   cout<<"Enter year:";
   cin>>(data.first())[i]; 
   cout<<"Enter bottles for that year:";
   cin>>(data.second())[i];
  }
}    
const std::string& Wine::Label()
{
  return name;
}

int Wine::sum()
{
  return (data.second()).sum();
}

void Wine::show()
{
  cout<<"Wine: "<<name<<endl;
  cout<<"\tYear"<<"\tBottles"<<endl;
  for (int i=0;i<years;i++)
    cout<<"\t"<<(data.first())[i]<<"\t"<<(data.second())[i]<<endl;
  cout<<endl;
}
