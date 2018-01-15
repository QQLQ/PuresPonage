#include<iostream>
#include<cstring>
#include"base.h"

using std::cout;
using std::endl;

//ABC base method
base::base(const char* l,int r)
{
 label=new char[strlen(l)+1];
 strcpy(label,l);
 rating=r;
}

base::base(const base& rs)
{
  label=new char[strlen(rs.label)+1];
  strcpy(label,rs.label);
  rating= rs.rating;
}
 
base::~base()
{
 delete [] label;
}

base& base::operator=(const base& rs)
{
  if (this==&rs)
    return *this;
  delete [] label;
  label=new char[strlen(rs.label)+1];
  strcpy(label,rs.label);
  rating=rs.rating;
}

std::ostream& operator<<(std::ostream& os, const base& rs)
{
  os<<"Label:"<<rs.label<<endl;
  os<<"Rating:"<<rs.rating<<endl;
  return os;
}

//baseDMA method
baseDMA::baseDMA(const char* l,int r):base(l,r){}

baseDMA::baseDMA(const baseDMA& rs):base(rs){}

void baseDMA::view()
{
  cout<<"baseDMA method view():"<<endl;
  cout<<*this;
}

//lacksDMA method
lacksDMA::lacksDMA(const char* c,const char* l,
    int r):base(l,r)
{
  strcpy(color,c);
}
lacksDMA::lacksDMA(const char* c,const lacksDMA &rs):base(rs)
{
  strcpy(color,c);
}
std::ostream& operator<<(std::ostream& os, const lacksDMA& rs)
{
  os<<"lacksDMA moethod<<:"<<endl;
  os<<(const base&)rs;
  os<<"Color:"<<rs.color<<endl;
  return os;
}
void lacksDMA::view()
{
  cout<<"lacksDMA moethod view:"<<endl;
  cout<<*this;
}

//hasDMA method
hasDMA::hasDMA(const char* s,const char* l,int r):base(l,r)
{
 style=new char[strlen(s)+1];
 strcpy(style,s);
}
hasDMA::hasDMA(const char*s,const hasDMA & rs):base(rs)
{
 style=new char[strlen(rs.style)+1];
 strcpy(style,rs.style);
}

hasDMA::hasDMA(const hasDMA& hs):base(hs)
{
 style=new char[strlen(hs.style)+1];
 strcpy(style,hs.style);
}
hasDMA::~hasDMA()
{
 delete [] style;
}
hasDMA& hasDMA::operator=(const hasDMA& rs)
{
 if (this==&rs)
   return *this;
 delete [] style;
 style=new char[strlen(rs.style)+1];
 strcpy(style,rs.style);
 base::operator=(rs);
} 
std::ostream& operator<<(std::ostream& os, const hasDMA& rs)
{
 cout<<"hasDMA method <<:"<<endl;
 cout<<(const base&)rs;
 cout<<"style:"<<rs.style<<endl;
 return os;
}
void hasDMA::view()
{
 cout<<"hasDMA method view:"<<endl;
 cout<<*this;
}
