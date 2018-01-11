#include<iostream>
#include<cstdlib>
#include<ctime>
#include"Queue.h"

const int MIN_PER_HR=60;
const int TEST_TIMES=5;
bool newcustomer(double x);

int main(void)
{
  using std::cin;
  using std::cout;
  using std::endl;
  using std::ios_base;
  std::srand(std::time(0));
  
  cout<<"Case study:Bank of Heather Automatic Teller\n";
  cout<<"Enter max size of queue:\n";
  int qs;
  cin>>qs;
  
  cout<<"Enter the number of simulation hours:\n";
  int hours;
  cin>>hours;
  if (hours<100)
   {
    cout<<"Simulation hours should be no less than 100 hours.Set to simulation hours to 100.\n";
    hours=100;
   }
  long cyclelimit=MIN_PER_HR*hours;
  
  cout<<"Enter the average number customers of hours:";
  double perhour;
  cin>>perhour;

  cout<<"Enter the offset (the smaller the more accurate,but will take more time):"<<endl;
  double offset;
  cin>>offset;
  if (offset<=0)
  {
   cout<<"offset cant be negative or 0,set to 1\n";
   offset=1;
  }
  double min_per_cust;
  double wait_time_tot; 
  long turnaways;
  long customers;
  long served;
  long sum_line;
  long wait_time1;
  long wait_time2;
  long line_wait;


do
{
min_per_cust=MIN_PER_HR/perhour;
perhour-=offset;
wait_time_tot=0;
for (int i=0;i<TEST_TIMES;i++)
{
  Queue line1(qs);
  Queue line2(qs);
  Item temp;
  turnaways=0;
  customers=0;
  served=0;
  sum_line=0;
  wait_time1=0;
  wait_time2=0;
  line_wait=0;
  
  for (int cycle=0;cycle<cyclelimit;cycle++)
  {
   if (newcustomer(min_per_cust))
   {
     if (line1.isfull()&&line2.isfull())
       turnaways++;
     else
      {
        customers++;
        temp.set(cycle);
        if (line1.queuecount()<line2.queuecount())
          line1.enqueue(temp);
        else
          line2.enqueue(temp);
       }
    }
    if (wait_time1<=0&&!line1.isempty())
     {
      line1.dequeue(temp);
      wait_time1=temp.ptime();
      line_wait+=cycle-temp.when();
      served++;
      }
    if (wait_time2<=0&&!line2.isempty())
     {
      line2.dequeue(temp);
      wait_time2=temp.ptime();
      line_wait+=cycle-temp.when();
      served++;
      }

     if (wait_time1>0)
       wait_time1--;
     if (wait_time2>0)
       wait_time2--;
     sum_line+=line1.queuecount()+line2.queuecount();
   }
  wait_time_tot+=(double)line_wait/served;
}
}  while (wait_time_tot/TEST_TIMES>1);
perhour+=offset;

cout<<"Average wait time<1:"<<wait_time_tot/TEST_TIMES<<endl;
cout<<"Perhour:"<<perhour<<endl;

return 0;
}

bool newcustomer(double x)
{
  return rand()*x/RAND_MAX<1;
}

//Unit of minute will not giva a satisfying result---too rough.
