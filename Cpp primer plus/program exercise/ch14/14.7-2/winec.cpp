#include"winec.h"

using std::valarray;
using std::cout;
using std::cin;
using std::endl;

Wine::Wine():std::string("Noname"),years(-1)
{
}

Wine::Wine(const char* l,int y,const int yt[],const int bot[]):std::string(l),years(y)
{
valarray<int> t1(yt,y);
valarray<int> t2(bot,y);
first()=t1;
second()=t2;
}

Wine::Wine(const char*l,int y):std::string(l),years(y)
{
first()=valarray<int> (y);
second()=valarray<int> (y);

}
 
void Wine::GetBottles()
{
 cout<<"Enter "<<(const std::string&)(*this)<<" data for "<<years<<" year(s):"<<endl;
 for (int i=0;i<years;i++)
  {
   cout<<"Enter year:";
   cin>>first()[i]; 
   cout<<"Enter bottles for that year:";
   cin>>second()[i];
  }
}    
const std::string& Wine::Label()
{
  return (const std::string&)(*this);
}

int Wine::sum()
{
  return second().sum();
}

void Wine::show()
{
  cout<<"Wine: "<<(const std::string&)(*this)<<endl;
  cout<<"\tYear"<<"\tBottles"<<endl;
  for (int i=0;i<years;i++)
    cout<<"\t"<<first()[i]<<"\t"<<second()[i]<<endl;
  cout<<endl;
}
