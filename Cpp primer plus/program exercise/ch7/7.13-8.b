#include<iostream>

const int SEASONS =4;

const char* SEASON[SEASONS] ={
   "Spring",
   "Summer",
   "Fall",
   "Winter"
       };
struct arr_stru {double ar[SEASONS];}; 
void fill(arr_stru*pstru);
void show(arr_stru stru);
    
int main(void)
{
  arr_stru stru;
  fill(&stru);
  show(stru);
  return 0;
}

void fill(arr_stru*pstru)
{
  using namespace std;
  for (int x=0;x<SEASONS;x++)
  {
    cout<<"Enter "<<SEASON[x]<<" expense:";
    cin>>pstru->ar[x];
  }
  return;
}

void show(arr_stru stru)
{
  using namespace std;
  double sum=0;
  cout<<"EXPENSE:"<<endl;
  for (int x=0;x<SEASONS;x++)
    {
     cout<<SEASON[x]<<":"<<stru.ar[x]<<endl;
     sum+=stru.ar[x];
     }
   cout<<"Total:"<<sum<<endl;
   return;
}  
