#include<stdio.h>
#include"pe12-2a.h"

void set_mode(int m);
void get_info(void);
void show_info(void);

static int mode;
static double distance;
static double fuel;

int main(void)
{
    int mode;

    printf("Enter 0 for metric mode,1 for US mode:");
    scanf("%d",&mode);
    while (mode>=0)
      {
       set_mode(mode);
       get_info();
       show_info();
       printf("Enter 0 for metric mode,1 for US mode");
       printf("(-1 to quit):");
       scanf("%d",&mode);
      }
     puts("DONE!");

return 0;
}

void set_mode(int m)
{
if (m!=1&&m!=0)
    printf("Invalid mode specified.MODE %s used.\n",mode==0?"0(metric)":"1(US)");
else 
   mode=m;
return;
}

void get_info(void)
{
  printf("Enter distance travelled in %s:",mode==0?"kilometers":"miles");
  scanf("%lf",&distance);

  printf("Enter fuel consumed in %s:",mode==0?"liters":"gallon");
  scanf("%lf",&fuel);

return;
}

void show_info(void)
{   
     double cons;
   
     if (mode==0)
      cons=M0;
     else if(mode==1)
      cons=M1;

    printf("Fuel consumption is %.4g %s.\n",cons,mode==0?MA0:MA1);

return;
}
