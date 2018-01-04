#include<iostream>
#include"time.h"

int main()
{
 using std::cout;
 using std::endl;
 Time aida(3,35);
 Time tosca(2,48);
 Time temp;
 
 cout<<"Aida and Tosca:\n";
 cout<<aida<<";"<<tosca<<endl;
 temp=aida+tosca;
 cout<<"A+T:"<<temp<<endl;
 temp=aida*1.17;
 cout<<"A*1.17:"<<temp<<endl;
 cout<<"10.0*Tosca:"<<10.0*tosca<<endl;
 return 0;
}
