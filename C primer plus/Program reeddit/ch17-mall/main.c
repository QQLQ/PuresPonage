#include"queue.h"
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define MIN_PER_HOUR 60.0    //Remember this must be double,so must be 60.0 instead of 60

bool newcustomer(double x);
ITEM customertime(long when); 

int main(void)
{
  QUEUE line;
  ITEM temp;
  int hours;
  int perhour;
  long cycle,cyclelimit;
  long turnaways=0;
  long customers=0;
  long served=0;
  long sum_line=0;
  int wait_time=0;
  double min_per_cust;
  long line_wait=0;

  Initialize(&line);
  srand((unsigned int)time(0));
  puts("Case study.");
  puts("Enter the number of stimulation hours.");
  scanf("%d",&hours);
  cyclelimit=hours*MIN_PER_HOUR;
  puts("Enter the average number of customer per hour.");
  scanf("%d",&perhour);
  min_per_cust=MIN_PER_HOUR/perhour;     //Or you will get a rough int.Then everything go burn.
  for (cycle=0;cycle<cyclelimit;cycle++){
  
  if (newcustomer(min_per_cust))
   {
     if (QueueIsFull(&line))
        turnaways++;
     else 
     {
      customers++;
      temp=customertime(cycle);
      AddItem(&line,temp);
     }
   }
 
  if (wait_time<=0&& !QueueIsEmpty(&line)){
   DeleteTheQueue(&line,&temp);
   wait_time=temp.processtime;
   line_wait+=cycle-temp.arrive;
   served++;
   }
  if (wait_time>0)
   wait_time--;
  sum_line+=QueueItemCount(&line);  
}

if (customers>0)
 {
  printf("*custmoer accepted:%ld\n",customers);
  printf(" customers served:%ld\n",   served);
  printf("        turnaways:%ld\n",turnaways);
  printf("Average Queuesize:%.2f\n",(double)sum_line/cyclelimit);
  printf("Average wait time:%.2f\n",(double)line_wait/served);
  }
else
  puts("No customers!");
EmptyTheQueue(&line);
puts("Bye!");

return 0;
}

bool newcustomer(double x){
  if ( rand()*x/RAND_MAX<1 )
    return true;
  else 
    return false;
}

ITEM customertime(long when)
{
   ITEM temp;
   temp.arrive=when;
   temp.processtime=rand()%3+1;
return temp;
} 
