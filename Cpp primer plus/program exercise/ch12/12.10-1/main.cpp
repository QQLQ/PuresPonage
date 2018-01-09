#include<iostream>
#include"Cow.h"

int main(void)
{
  using namespace std;
  Cow t1;
  Cow t2("Marry","Fly",52);
  cout<<"t1:"<<endl;
  t1.ShowCow();
  cout<<"t2:"<<endl;
  t2.ShowCow();
  cout<<"t1=t2:"<<endl;
  t1=t2;
  cout<<"t3=t1:"<<endl;
  Cow t3=t1;
  t3.ShowCow();
return 0;
}
