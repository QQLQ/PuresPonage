#include<iostream>
#include"complex0.h"

complex::complex()
{
  m_real=m_imaginary=0.0;
}
complex::complex(double a,double b)
{
 if (b==0)
 {
  std::cout<<"The imaginary part can not be 0.Set to 1\n";
  b=1;
 }
 m_real=a;
 m_imaginary=b;
}
complex complex::operator+(const complex&t) const
{
 return complex(m_real+t.m_real,m_imaginary+t.m_imaginary);
}
complex complex::operator-(const complex&t) const
{
 return complex(m_real-t.m_real,m_imaginary-t.m_imaginary);
}
complex complex::operator*(const complex&t) const
{
 return complex(m_real*t.m_real-m_imaginary*t.m_imaginary,
                m_real*t.m_imaginary+m_imaginary*t.m_real);
}
complex complex::operator~()
{
 return complex(m_real,-m_imaginary);
}
complex operator*(const complex&t,double n)
{
 return complex(t.m_real*n,t.m_imaginary*n);
}
complex operator*(double n,const complex&t)
{
 return complex(n*t.m_real,n*t.m_imaginary);
}
std::ostream& operator<<(std::ostream&os,const complex&t)
{
 os<<"("<<t.m_real<<","<<t.m_imaginary<<"i)";
 return os;
}
std::istream& operator>>(std::istream&is,complex&t)
{
 using std::cout;
 using std::cin;
 cout<<"real:";
 if (!(is>>t.m_real))
   return is;
 cout<<"imaginary:";
 is>>t.m_imaginary;
 while (cin.get()!='\n');
 return is;
}
