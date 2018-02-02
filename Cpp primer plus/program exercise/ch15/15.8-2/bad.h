#include<iostream>
#include<stdexcept>

class bad_hmean:public std::logic_error
{
private:
  double v1;
  double v2;
public:
  bad_hmean(double a=0,double b=0,const char* str="invalid arguments:a=-b\n"):
logic_error(str),v1(a),v2(b){}
};



class bad_gmean:public std::logic_error
{ 
public:
  double v1;
  double v2;
  bad_gmean(double a=0,double b=0,const char* str="gmean() arguments should be >= 0\n"):
v1(a),v2(b),logic_error(str){}
};


