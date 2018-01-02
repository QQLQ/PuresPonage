#include<iostream>
#include<cstring>
#include"plorg.h"

plorg::plorg(const char* name,int CI)
{
 strcpy(m_name,name);
 m_CI=CI;
}
void plorg::setCI(int CI)
{
 m_CI=CI;
}
void plorg::show(void)
{
  std::cout<<"Name:"<<m_name<<" ,CI="<<m_CI<<std::endl;
}
