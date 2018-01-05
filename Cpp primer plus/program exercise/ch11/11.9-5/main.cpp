#include<iostream>
#include"Stonewt.h"

int main(void)
{
  using std::cout;
  using std::endl;
  Stonewt t1;
  t1=15;
  cout<<"t1:"<<t1;
  Stonewt t2(122,15,Stonewt::pounds_fp);
  cout<<t2;
  t2=127.8;
  cout<<"t2:"<<t2;
  cout<<"t1+t2:"<<t1+t2;
  cout<<"t2*2.2:"<<t2*2.2;
  cout<<"3.2*t2:"<<3.2*t2;
  cout<<"t2-t1:"<<t2-t1;
  return 0;
}
