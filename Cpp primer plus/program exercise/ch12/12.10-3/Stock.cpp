#include<iostream>
#include<cstring>
#include"Stock.h"

Stock::Stock()
{
 int len=strlen("no name");
 company=new char[len+1];
 strcpy(company,"no name");
 shares=0;
 share_val=total_val=0.0;
} 
Stock::Stock(const std::string& co,long n,double pr)
{
 int len=co.size();
 company=new char[len+1];
 const char*pt=&co[0];
 int i=0;
 while (*pt)
  company[i++]=*pt++;
 company[i]='\0';
 if (n<0)
  {
    std::cout<<"Number of shares can't be negative;"
             <<company<<" shares set ro 0.\n";
             shares=0;
  }
  else 
     shares=n;
 share_val=pr;
 set_tot();
}
Stock::~Stock()
{
  delete []company;
}
void Stock::buy(long num,double price)
{
 if (num<0)
  {
    std::cout<<"Number of shares purchased can't be negative."
      <<"Transacation is aborted.\n";
  }
  else
  {
    shares+=num;
    share_val=price;
    set_tot();
  }
}
void Stock::sell(long num,double price)
{
  using std::cout;
  if (num<0)
  {
    cout<<"Number of shares sold can't be negative. Transaction is aborted.\n";
  }
  else if(num>shares)
  {
    cout<<"You can't sell more than you have!Transaction is aborted.\n";
  }
  else 
  {
    shares-=num;
    share_val=price;
    set_tot();
  }
}
void Stock::update(double price)
{
  share_val=price;
}
const Stock & Stock::topval(const Stock& s) const
{
 if (s.total_val>total_val)
   return s;
 else 
   return *this;
}
std::ostream& operator<<(std::ostream& os,const Stock& s)
{
  using std::ios_base;
  ios_base::fmtflags orig=os.setf(ios_base::fixed,ios_base::floatfield);
  std::streamsize prec=os.precision(3);
  os<<"Company"<<s.company
    <<" Shares:"<<s.shares<<'\n';
  os<<"   Share price:$"<<s.share_val;
  os.precision(2);
  os<<" Total Worth:$"<<s.total_val<<'\n';
  os.setf(orig,ios_base::floatfield);
  os.precision(prec);
}
