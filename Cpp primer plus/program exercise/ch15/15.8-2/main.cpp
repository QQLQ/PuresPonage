#include<iostream>
#include<cmath>
#include"bad.h"

double hmean(double a,double b);
double gmean(double a,double b);
int main()
{
  using std::cout;
  using std::cin;
  using std::endl;
  
  double x,y,z;
  
  cout<<"Enter two numbers:";
  while (cin>>x>>y)
  {
    try{
      z=hmean(x,y);
      cout<<"Harmonic mean of "<<x<<" and  "<<y
          <<" is "<<z<<endl;
      cout<<"Geometric mean of "<<x<<" and "<<y
          <<" is "<<gmean(x,y)<<endl;
      cout<<"Enter next se of numbers <q to quit>:";
       }
      catch(bad_hmean& bg)
      {
        cout<<bg.what();;
        cout<<"Try again.\n";
        continue;
       }
       catch(bad_gmean&hg)
       {
        cout<<hg.what();
        cout<<"Values used:"<<hg.v1<<" ,"<<hg.v2<<endl;
        cout<<"Sorry, you don't get to paly anymore.\n";
        break;
       }
   }
   cout<<"Bye!\n";
   return 0;
}

double hmean(double a,double b)
{
  if (a==-b)
    throw bad_hmean(a,b);
  return 2.0*a*b/(a+b);
}

double gmean(double a,double b)
{
  if (a<0||b<0)
    throw bad_gmean(a,b);
  return std::sqrt(a*b);
}
