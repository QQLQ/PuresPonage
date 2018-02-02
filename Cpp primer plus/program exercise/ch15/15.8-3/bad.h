#include<iostream>
#include<stdexcept>

class bexc:public std::logic_error
{
private:
 double v1;
 double v2;
public:
 bexc(double a,double b,const char* str):v1(a),v2(b),logic_error(str){}
 double aval(){return v1;}
 double bval(){return v2;}
 virtual ~bexc() throw(){}
 };

class bad_hmean:public bexc
{
public:
  bad_hmean(double a=0,double b=0,const char* str="bad h_mean:invalid arguments:a=-b"):
bexc(a,b,str){}
  virtual void report();
};
void bad_hmean::report()
{
  using std::cout;
  using std::endl;
  cout<<"a,b= "<<aval()<<", "<<bval()<<endl;
  cout<<what()<<endl;
}

class bad_gmean:public bexc
{ 
public:
  bad_gmean(double a=0,double b=0,const char* str="gmean() arguments should be >= 0"):
bexc(a,b,str){}
  virtual void report();  
};

void bad_gmean::report()
{
  using std::cout;
  using std::endl;
  cout<<"a,b= "<<aval()<<", "<<bval()<<endl;
  cout<<what()<<endl;
}
