#include<iostream>
#include<cstring>
#include"class.h"
using std::cout;
using std::endl;

Cd::Cd(const char* s1,const char* s2, int n, double x)
{
 strcpy(performers,s1);
 strcpy(label,s2);
 selections=n;
 playtime=x;
}
 
Cd::Cd(const Cd& d)
{
 strcpy(performers,d.performers);
 strcpy(label,d.label);
 selections=d.selections;
 playtime=d.playtime;
}
Cd::Cd()
{
 strcpy(performers,"Noperformer_");
 strcpy(label,"nolabel_");
 selections=0;
 playtime=0.0;
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
 strcpy(performers,d.performers);
 strcpy(label,d.label);
 selections=d.selections;
 playtime=d.playtime;
}

Classic::Classic():Cd()
{
 strcpy(pwork,"Nowork_");
}
 
Classic::Classic(const char* s1,const char* s2,const char* s3,int n, double x):Cd(s1,s2,n,x)
{
 strcpy(pwork,s3);
}

Classic::Classic(const Classic&d):Cd(d)
{
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
  Cd::operator=(d);
  strcpy(pwork,d.pwork);
}
