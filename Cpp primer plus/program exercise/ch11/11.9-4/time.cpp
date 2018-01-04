#include<iostream>
#include"time.h"

Time::Time()
{
m_hours=m_minutes=0;
}
Time::Time(int h,int m)
{
  if (h<0||m<0)
  {
   std::cout<<"Hour and minutes must not be negative.set both to zero.\n";
   h=m=0;
  } 
  int total=h*60+m;
  m_hours=total/60;
  m_minutes=total%60;
} 
void Time::AddMin(int m)
{
  int total=m_hours*60+m_minutes+m;
  m_hours=total/60;
  m_minutes=total%60;
}
void Time::AddHr(int h)
{
  int total=(m_hours+h)*60+m_minutes;
  m_hours=total/60;
  m_minutes=total%60;
}
void Time::Reset(int h,int m)
{
 *this=Time(h,m);  
}
Time operator+(const Time & t1,const Time & t2)
{
 return Time(t1.m_hours+t2.m_hours,t1.m_minutes+t2.m_minutes);
}
Time operator-(const Time & t1,const Time & t2)
{
 return Time(t1.m_hours-t2.m_hours,t1.m_minutes-t2.m_minutes);
}
Time operator*(const Time & t,double n)
{
  int total=t.m_hours*n*60+t.m_minutes*n;
 return Time(total/60,total%60);
}
Time operator*(double n,const Time & t)
{
 return t*n;
}
std::ostream & operator<<(std::ostream& os,const Time &t)
{
 os<<t.m_hours<<" hours, "<<t.m_minutes<<" minutes";
 return os;
}
