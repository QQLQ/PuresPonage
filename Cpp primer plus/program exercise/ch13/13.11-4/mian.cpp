#include<iostream>
#include"port.h"

int main(void)
{
  Port t1("Gallo","tawny",20);
  cout<<"Method Show() for Port:"<<endl;
  t1.Show();
  cout<<"Method << for Port:"<<endl;
  cout<<t1<<endl;
  
  VintagePort t2("Lafite",30,"FFF",999);
  cout<<"Method Show() for VintagePort:"<<endl;;
  t2.Show();
  cout<<"Method << for VintagePort:"<<endl;
  cout<<t2<<endl<<endl;

  cout<<"For copy constructor and copy assignment function in Port."<<endl;
  Port t3=t1;
  t3.Show();
  cout<<t3<<endl<<endl;
  
  Port t4;
  t4=t1;
  t4.Show();
  cout<<t4<<endl<<endl;
    
  cout<<"For copy constructor and copy assignment function in VintagePort."<<endl;
  VintagePort t5=t2;
  t5.Show();
  cout<<t5<<endl<<endl;
  
  VintagePort t6;
  t6=t2;
  t6.Show();
  cout<<t6<<endl<<endl;

  return 0;
}
