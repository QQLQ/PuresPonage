#include<iostream>
#include<cstring>
#include"golf.h"

static char* sgets(char*line,int size);
inline void eatline(void){while (std::cin.get()!='\n');}

int setgolf(golf & g)
{ 
  using std::cout;
  using std::cin;
  using std::endl;  
  char name[LEN];
  int temp;
  cout<<"Please enter the name:";
  cin.getline(name,LEN);
  if (name[0]=='\0')
    return 0;
  cout<<"Please enter the handicap value:";
  cin>>temp;
  eatline();
  strncpy(g.fullname,name,LEN);
  g.handicap=temp;
  return 1;
}

void handicap(golf & g,int hc)
{
   g.handicap=hc;
} 
void showgolf(const golf & g)
{
 std::cout<<"Name :"<<g.fullname<<" hc :"<<g.handicap<<std::endl;
}
