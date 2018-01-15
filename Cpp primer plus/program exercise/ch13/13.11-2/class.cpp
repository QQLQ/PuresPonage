#include<iostream>
#include<cstring>
#include"class.h"
using std::cout;
using std::endl;

Cd::Cd(const char* s1,const char* s2, int n, double x)
{ 
 performers=new char[strlen(s1)+1];
 label=new char[strlen(s2)+1];
 strcpy(performers,s1);
 strcpy(label,s2);
 selections=n;
 playtime=x;
}
 
Cd::Cd(const Cd& d)
{
 performers=new char[strlen(d.performers)+1];
 label=new char[strlen(d.label)+1];
 strcpy(performers,d.performers);
 strcpy(label,d.label);
 selections=d.selections;
 playtime=d.playtime;
}
Cd::Cd()
{
 performers=new char[1];
 label=new char[1];
 strcpy(performers,"");
 strcpy(label,"");
 selections=0;
 playtime=0.0;
}

Cd::~Cd()
{
  delete [] performers;
  delete [] label;
}

void Cd::Report() const
{
 cout<<"performers:"<<performers<<endl;
 cout<<"label:"<<label<<endl;
 cout<<"selections:"<<selections<<endl;
 cout<<"playtime:"<<playtime<<endl;
 return;
}
Cd& Cd::operator=(const Cd& d)
{
 if (this==&d)
   return *this;
 delete [] performers;
 delete [] label;
 performers=new char[strlen(d.performers)+1];
 label= new char[strlen(label)+1];  
 strcpy(performers,d.performers);
 strcpy(label,d.label);
 selections=d.selections;
 playtime=d.playtime;
}

Classic::Classic():Cd()
{
 pwork=new char[1];
 strcpy(pwork,"");
}
 
Classic::Classic(const char* s1,const char* s2,const char* s3,int n, double x):Cd(s1,s2,n,x)
{
 pwork=new char[strlen(s3)+1];
 strcpy(pwork,s3);
}

Classic::Classic(const Classic&d):Cd(d)
{
 pwork=new char[strlen(d.pwork)+1];
 strcpy(pwork,d.pwork);  
}

void Classic::Report() const
{
  Cd::Report();
  cout<<"Pwork:"<<pwork<<endl<<endl;
  return;
}
Classic& Classic::operator=(const Classic& d)
{
  if (this ==&d)
    return *this;
  Cd::operator=(d);
  delete []pwork;
  pwork=new char[strlen(d.pwork)+1];
  strcpy(pwork,d.pwork);
}

Classic::~Classic()
{
  delete [] pwork;
}
