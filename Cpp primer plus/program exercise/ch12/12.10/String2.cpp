#include<iostream>
#include<cstring>
#include<cctype>
#include"String2.h"

String::String()
{
 str=new char[1];
 str[0]='\0';
 len=1;
}
String::String(const char*line)
{
 len=strlen(line);
 str=new char[len+1];
 strcpy(str,line);
}
String::String(const String&t)
{
 len=t.len;
 delete[]str;
 str=new char[len+1];
 strcpy(str,t.str);
} 
String::~String()
{
 delete []str;
}
String& String::operator=(const String&t)
{
  if (this==&t)
    return *this;
  len=t.len;
  delete[]str;
  str=new char[len+1];
  strcpy(str,t.str);
}
bool String::operator==(const String&t) const
{
  return strcmp(t.str,str)==0;
} 
String String::operator+(const String&t) const
{
 String temp;
 temp.len=len+t.len;
 temp.str=new char[temp.len+1];
 strcpy(temp.str,str);
 strcat(temp.str,t.str);
 return temp;
}
String String::operator+(const char*line) const
{
 return *this+String(line);
}
void String::stringup(void)
{
 for (int i=0;i<len;i++)
   str[i]=toupper(str[i]);
 return;
}
void String::stringlow(void) 
{
 for (int i=0;i<len;i++)
   str[i]=tolower(str[i]);
 return;
}
int String::has(char ch) const
{
  int count=0;
  for (int i=0;i<len;i++)
    if (str[i]==ch)
      count++;
  return count;
}
std::ostream& operator<<(std::ostream& os,const String& t)
{
  os<<t.str;
  return os;
}
std::istream& operator>>(std::istream& is,String& t)
{
  char temp[String::MSIZE];
  std::cin.get(temp,String::MSIZE);
  while (std::cin.get()!='\n');
  t=temp;
  return is;
}
String operator+(const char*line,const String&t)
{
 return String(line)+t;
}
