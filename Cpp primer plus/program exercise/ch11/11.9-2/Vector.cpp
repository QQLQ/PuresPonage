
#include<iostream>
#include<cmath>
#include"Vector.h"
using std::atan;
using std::atan2;
using std::sqrt;
using std::cos;
using std::sin;
using std::cout;

namespace VECTOR{
const double Rad_to_deg=45.0/atan(1.0);

void Vector::polar_mode(){
mode=POL;
}
void Vector::rect_mode(){
mode=RECT;
}
Vector::Vector(){
x=y=0.0;
mode=RECT;
}
double Vector::magval() const{
return sqrt(x*x+y*y);
}
double Vector::angval() const{
if (x==0&&y==0)
 return 0.0;
else
 return atan2(y,x)*Rad_to_deg;
}

Vector::Vector(double n1,double n2,Mode form){
mode=form;
if (mode==RECT)
 { 
  x=n1;
  y=n2;
 }
 else if(mode==POL)
 {
  x=n1*cos(n2/Rad_to_deg);
  y=n1*sin(n2/Rad_to_deg);
 }
 else
 {
  cout<<"Incorrect 3rd argument to Vector()--";
  cout<<"Vector set to 0\n";
  x=y=0.0;
  mode=RECT;
  }
} 
void Vector::reset(double n1,double n2,Mode form){
mode=form;
if (mode==RECT)
 { 
  x=n1;
  y=n2;
 }
 else if(mode==POL)
 {
  x=n1*cos(n2/Rad_to_deg);
  y=n1*sin(n2/Rad_to_deg);
 }
 else
 {
  cout<<"Incorrect 3rd argument to Vector()--";
  cout<<"Vector set to 0\n";
  x=y=0.0;
  mode=RECT;
  }
} 
Vector Vector::operator+(const Vector & b) const{
   return Vector(x+b.x,y+b.y);
}
Vector Vector::operator-(const Vector & b) const{
   return Vector(x-b.x,y-b.y);
}
Vector Vector::operator-() const{
   return Vector(-x,-y);
}
Vector Vector::operator*(double n) const{
   return Vector(x*n,y*n);
}
Vector operator*(double n,const Vector & a){
   return a*n;
}
std::ostream& operator<<(std::ostream & os,const Vector & v){
   if (v.mode==Vector::RECT)
     os<<"(x,y)=("<<v.x<<","<<v.y<<")";
   else if(v.mode==Vector:: POL)
    {
     os<<"(m,a)=("<<v.magval()<<","<<v.angval()<<")";
    }
   else 
     os<<"Vecotr object mode is invalid";
   return os;
}
}
