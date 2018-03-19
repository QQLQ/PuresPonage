#include<iostream>
#include<list>
#include<typeinfo>
#include<algorithm>
using namespace std;

template<typename T>
list<T> average_list(initializer_list<T> ili)
{
 return list<T>(ili.begin(),ili.end());
}

template<typename T>
ostream& operator<<(ostream& os,list<T> li)
{
 li.sort();
 for(auto pt=li.rbegin();pt!=li.rend();pt++)
  cout<<(*pt)<<" ";
return os;
}
int main()
{
 using namespace std;
 auto q=average_list({15.3,10.7,9.0});
 cout<<q<<endl;
 cout<<average_list({20,30,19,17,45,38})<<endl;
 auto ad=average_list<double>({'A',70,65.33});
 cout<<ad<<endl;
 return 0;
}
