#include<iostream>
#include<cstring>
#include"Cow.h"

Cow::Cow()
{
  name[0]='\0';
  hobby=new char[1];
  hobby[0]='\0';
  weight=0;
  std::cout<<"Default constructor\n";
} 
Cow::Cow(const char*nm,const char* ho,double wt)
{
  strncpy(name,nm,19);
  name[19]='\0';
  hobby=new char[strlen(ho)+1];
  strcpy(hobby,ho);
  weight=wt;
  std::cout<<"Constructor\n";

}
Cow::Cow(const Cow &c)
{
  delete[]hobby;
  strncpy(name,c.name,19);
  name[19]='\0';
  hobby=new char[strlen(c.hobby)+1];
  strcpy(hobby,c.hobby);
  weight=c.weight;
  std::cout<<"Copy constructor\n";
}
Cow::~Cow()
{
 delete[]hobby;
 std::cout<<"Destructor\n";
}
Cow& Cow::operator=(const Cow&c)
{
 if (this==&c)
   return *this;
 delete[]hobby;
 strncpy(name,c.name,19);
 name[19]='\0';
 hobby=new char[strlen(c.hobby)+1];
 strcpy(hobby,c.hobby);
 weight=c.weight;
 std::cout<<"Assignment opeartor\n";

}
void Cow::ShowCow() const
{
  using std::cout;
  using std::endl;
  cout<<"Name:"<<name<<endl;
  cout<<"hobby:"<<hobby<<endl;
  cout<<"weight:"<<weight<<endl;
  return;
}
