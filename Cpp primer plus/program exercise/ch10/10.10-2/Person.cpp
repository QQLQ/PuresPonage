#include<iostream>
#include<cstring>
#include"Person.h"

Person::Person(const std::string & ln,const char * fn)
{
 lname=ln;
 strcpy(fname,fn);
}
void Person::Show() const
{
 std::cout<<fname<<" "<<lname<<std::endl;
 return;
}
void Person::FormalShow() const
{
 std::cout<<lname<<" "<<fname<<std::endl;
}
