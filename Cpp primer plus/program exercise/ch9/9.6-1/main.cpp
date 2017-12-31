#include<iostream>
#include<cstring>
#include"golf.h"

const int SSIZE=5;

char showmenu(void);
inline void eatline(void){  while (std::cin.get()!='\n');}

int main(void)
{
  using std::cout;
  using std::cin;
  using std::endl;
  char name[40];
  int temp;
  golf ar[SSIZE];
  int num=0;
  char ch;
    
  while (ch=showmenu(),1)
  {
    switch(ch)
     {
      case 'a':if (num==0)
                  cout<<"No data."<<endl;
               else 
                 for (int i=0;i<num&&ar[i].fullname[0];i++)
                  showgolf(ar[i]);
               continue;
      case 'b':while (num<SSIZE)
                if (setgolf(ar[num]))
                  num++;
                else 
                  break;
               continue;
      case 'c':cout<<"Please enter the name of the person whose hc you wanna reset:";
               cin.get(name,LEN);
               eatline();
               {
                int i;
               for (i=0;i<num;i++)
               {
                if (!strcmp(ar[i].fullname,name))
                 {
                  cout<<"Please enter the value you wanna set for "<<name<<":";
                  cin>>temp;
                  eatline();
                  handicap(ar[i],temp);
                  break;
                  }
                }
               if (i==num)
                 cout<<"No matched value"<<endl;
                }   
               continue;
      case 'q':break;
     }
     break;
   }
   cout<<"Bye!"<<endl;
   return 0;                   
}

char showmenu(void)
{  
  using std::cout;
  using std::cin;
  using std::endl;
  char ch;
  cout<<"Welcome to GMM"<<endl;
  cout<<"a.)show the list.    b.)enter data"<<endl;
  cout<<"c.)reset handicap    q.)quit"<<endl;
  cout<<"Please enter your choice:";
  cin>>ch;
  eatline();
  while (!strchr("abcq",ch))
   {
    cout<<"Invalid input,enter again(q to quit):";
    cin>>ch;
    eatline();
   }
return ch;
}
