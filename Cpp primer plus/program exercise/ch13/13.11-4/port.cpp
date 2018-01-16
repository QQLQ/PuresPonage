#include<iostream>
#include<cstring>
#include"port.h"

//Port as base class, method.
Port::Port(const char *br,const char * st,int b)
{
 brand=new char[strlen(br)+1];
 strcpy(brand,br);
 strcpy(style,st);
 bottles=b;
}
Port::Port(const Port& p)
{
 brand=new char[strlen(p.brand)+1];
 strcpy(brand,p.brand);
 strcpy(style,p.style);
 bottles=p.bottles;
}
Port& Port::operator=(const Port&p)
{
 if (this==&p)
    return *this;
 delete[]brand;
 brand=new char[strlen(p.brand)+1];
 strcpy(brand,p.brand);
 strcpy(style,p.style);
 bottles=p.bottles;
 return *this;
} 
Port& Port::operator+=(int b)
{
 bottles+=b;
 return *this;
}
Port& Port::operator-=(int b)
{
 bottles-=b;
 return *this;
} 
void Port::Show() const
{
 cout<<"Brand:"<<brand<<endl;
 cout<<"Kind:"<<style<<endl;
 cout<<"Bottles:"<<bottles<<endl;
 return;
} 
ostream& operator<<(ostream& os,const Port& p)
{
  os<<p.brand<<","<<p.style<<","<<p.bottles;
  return os;
}
//VintagePort as public derived class from Port,method
VintagePort::VintagePort():Port()
{
 nickname=new char[strlen("No_nickname")+1];
 strcpy(nickname,"No_nickname");
 year=0;
}
VintagePort::VintagePort(const char *br,int b, const char* nn,int y):Port(br,"vintage",b)
{
 nickname=new char[strlen(nn)+1];
 strcpy(nickname,nn);
 year=y;
} 
VintagePort::VintagePort(const VintagePort& vp):Port(vp)
{
 nickname=new char[strlen(vp.nickname)+1];
 strcpy(nickname,vp.nickname);
 year=vp.year;
}
VintagePort& VintagePort::operator=( const VintagePort& vp)
{
 if (this==&vp)
    return *this;
 Port::operator=(vp);
 delete []nickname;
 nickname=new char[strlen(vp.nickname)+1];
 strcpy(nickname,vp.nickname);
 year=vp.year;
 return *this;
}
void VintagePort::Show() const
{
  Port::Show();
  cout<<"Nickname:"<<nickname<<endl;
  cout<<"Year:"<<year<<endl;
}
ostream& operator<<(ostream& os,const VintagePort& vp)
{
  os<<(const Port&)vp;
  cout<<","<<vp.nickname<<","<<vp.year;
  return os;
}
/*task b:why certain methods are redefined and some are not.
 The base define methods such as operator += works perfectly fine even we do not redefine it.Since
 it only deals with the data members in base class.So we do not need to redefined.It.
 The void show(),on the contrast, have to dealt with the new data memeber 'nick name' and 'year',
 which the base defined can not satisfy what we need.Then we redefine them.
 
 task c: why operator= and opeartor<< are not virtual.
 The virtual method in derived class shoubld have the same parameter list as the base class do.
 But the derived class has the default copy assignment whose parameter is its own class 
 reference, which is different from the virtual = from the base method.In another word, when we  
 use it to assgin to the derived class object, we use the default one instead of the virtual 
 redefined one. So making copy assignment virtual in base class dose not help---instead, it 
 causes confusion.As Stroustrup says we shoudld not pay for the features that we do not need.
 As for operator<< which is friend function, cant not be virtual due to its feature of 
 non-member function.*/
