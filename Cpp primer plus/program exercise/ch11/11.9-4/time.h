#include<iostream>
#ifndef MYTIME_H_
#define MYTIME_H_
class Time{
private:
  int m_hours;
  int m_minutes;
public:
  Time();
  Time(int h,int m=0); 
  void AddMin(int m);
  void AddHr(int h);
  void Reset(int h=0,int m=0);
  friend Time operator+(const Time & t1,const Time & t2);
  friend Time operator-(const Time & t1,const Time & t2);
  friend Time operator*(const Time & t,double n);
  friend Time operator*(double n,const Time & t);
  friend std::ostream& operator<<(std::ostream& os,const Time &t);
  };
#endif
