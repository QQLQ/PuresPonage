#include<iostream>
#include"base.h"

const int TSIZE=3;

int main(void)
{
 using std::cout;
 using std::cin;
 using std::endl;

 base* pt[TSIZE];
 char label[40];
 int rating;
 char color[30];
 char style[40];
 int choice;
 
 for (int i=0;i<TSIZE;i++)
 {
  cout<<"Enter label:";
  cin.getline(label,40);
  cout<<"Enter rating:";
  cin>>rating;
  while (cin.get()!='\n');
  cout<<"## 1 for baseDMA,2 for lacksDMA, 3 for has DMA"<<endl;
  cout<<"Please enter your choice:";
  while (1) 
  {
   if (!(cin>>choice))
    {
     cin.clear();
     while (cin.get()!='\n');
     cout<<"Invalid choice,reenter please:";
     continue;
    }
   else
   {
    while (cin.get()!='\n');
    cout<<"CHOICE::"<<choice<<endl; 
    switch (choice)
   {
    case 1:pt[i]=new baseDMA(label,rating);break;
    case 2:cout<<"Please enter color:";
           cin.getline(color,30);
           pt[i]=new lacksDMA(color,label,rating);
           break;
    case 3:cout<<"Please enter style:";
           cin.getline(style,40);
           pt[i]=new hasDMA(style,label,rating);
           break;
    default:cout<<"Invalid choice,reenter please:";
           continue;
   }
   break;
  }
  }
}
  cout<<endl;
  
  cout<<"using method operator<<():"<<endl<<endl;
  
  for (int i=0;i<TSIZE;i++)
   cout<<"#"<<i+1<<":"<<(*pt[i])<<endl;  //friend method can not be applied to virtual method;
                                         //so which function will be called depend on pointer type.
  cout<<"using method view():"<<endl;
  
  for (int i=0;i<TSIZE;i++)
  {
   cout<<"#"<<i+1<<":";
   pt[i]->view();
   cout<<endl;
  }

  baseDMA t1("A~~",2);
  lacksDMA t2("pink","B~~",34);
  hasDMA t3("Poi~","C~",2332);

  cout<<t1;
  cout<<t2;
  cout<<t3;

  for (int i=0;i<TSIZE;i++)
   delete pt[i];
   
   cout<<"Done!"<<endl;
   return 0;
}
