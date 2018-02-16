#include<iostream>
#include<algorithm>
#include<cstdlib>
#include<ctime>

const int ARSIZE=10;
const long MaxTestNumber=10; 

int reduce(long ar[],int n);
void show(long ar[],int n);

int main(void)
{
 using std::srand;
 using std::rand;
 using std::endl;
 using std::cout;

 int size=ARSIZE; 
 long ar[ARSIZE];
 srand(time(0));
 int i;
 for (i=0;i<ARSIZE;i++)
   ar[i]=rand()%(MaxTestNumber+1);
 cout<<"Before reduced:"<<endl;
 show(ar,ARSIZE);
 cout<<"the size is "<<size<<endl;

 size=reduce(ar,ARSIZE);
 cout<<endl<<"After reduced:"<<endl;
 show(ar,size);
 cout<<"the size is "<<size<<endl;
return 0;
}
 
 int reduce(long ar[],int n)
{
  std::sort(&ar[0],&ar[n]);
  long* pt= std::unique(&ar[0],&ar[n]);
  return (pt-&ar[0]);
}

void show(long ar[],int n)
{
  using std::endl;
  using std::cout;
 int i;
 for (i=0;i<n;i++)
 { 
  cout<<ar[i]<<" ";
  if ((i+1)%5==0)
   cout<<endl;
 }
 if (i%5!=0)
   cout<<endl;
}
