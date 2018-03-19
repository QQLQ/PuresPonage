#include<iostream>
#include<string>
using namespace std;

class Cpmv
{
public:
  struct Info
  {
    std::string qcode;
    std::string zcode;
  };
private:
  Info*pi;
public:
  Cpmv();
  Cpmv(std::string q,std::string z);
  Cpmv(const Cpmv& cp);
  Cpmv(Cpmv&& mv);
  ~Cpmv();
  Cpmv& operator=(const Cpmv&cp);
  Cpmv& operator=(Cpmv&&mv);
  Cpmv operator+(const Cpmv&obj)const;
  void Display()const;
};

int main(void)
{
 cout<<"Default constructor:<<<"<<endl;
 Cpmv c1; 
 cout<<"Common constructor:<<<"<<endl;
 Cpmv c2("one","two");
 cout<<"Copy constructor:<<<"<<endl;
 Cpmv c3(c2);
 c3.Display();
 cout<<"Move constructor:<<<"<<endl;
 Cpmv c4(c2+c3);
 c4.Display();
 cout<<"operator =:<<<"<<endl;
 c1=c2;
 cout<<"move operator =:<<<"<<endl;
 c1=(c2+c3);
 c1.Display();
 cout<<"Done"<<endl;
 return 0;
}

Cpmv::Cpmv()
{
  pi=new Info;
  cout<<"Default constructor"<<endl;
}  
Cpmv::Cpmv(std::string q,std::string z)
{
  Info i;
  i.qcode=q;
  i.zcode=z;
  pi=new Info(i);
  cout<<"Constructor"<<endl;
}
Cpmv::Cpmv(const Cpmv& cp)
{
 pi=new Info(*(cp.pi));
 cout<<"Copy constructor"<<endl;
}
Cpmv::Cpmv(Cpmv&& mv)
{
 pi=mv.pi;
 mv.pi=nullptr;
 cout<<"Move constructor"<<endl;
} 
Cpmv::~Cpmv()
{
 delete pi;
}
Cpmv& Cpmv::operator=(const Cpmv&cp)
{
  if(this==&cp)
   return *this;
  delete pi;
  pi=new Info(*(cp.pi));
  cout<<"Operator ="<<endl;
  return *this;
}
Cpmv& Cpmv::operator=(Cpmv&&mv)
{
  if(this==&mv)
   return *this;
  delete pi;
  pi=mv.pi;
  mv.pi=nullptr;
  cout<<"Move Operator ="<<endl;
  return *this;
}
Cpmv Cpmv::operator+(const Cpmv&obj)const
{
 return Cpmv(pi->qcode+obj.pi->qcode,pi->zcode+obj.pi->zcode);
}
void Cpmv::Display()const
{
 cout<<pi->qcode<<" "<<pi->zcode<<endl;
}
