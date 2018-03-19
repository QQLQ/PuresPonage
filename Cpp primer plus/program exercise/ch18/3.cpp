#include<iostream>

using namespace std;
static long double tot=0.0; 


long double sum_val(void){}

template<typename T,typename ...Args>
long double sum_val(T val,Args...args)
{
 tot+=val;
 sum_val(args...);
 return tot;
}


int main(void)
{
cout<<sum_val(10.5,23.4,52,100)<<endl;
return 0;
}
