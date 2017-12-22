#include<stdio.h>
#include"pe12-2a.h"

static int counts;      //check here,btw the "counts" has already been initialized to 0 as it is external variable.

int set_mode(int m,int *pprev);
void get_info(int mode,double *pdist,double *pfue);
void show_info(int mode,const double distance,const double fuel);

int main(void)
{
    int mode,prev;
    int *pprev;
    double dist,fue;
    double *pdist,*pfue;
    prev=0;
    pprev=&prev;
    pdist=&dist;
    pfue=&fue;

    printf("Enter 0 for metric mode,1 for US mode:");
    scanf("%d",&mode);
    while (mode>=0)
      {
       mode=set_mode(mode,pprev);
       get_info(mode,pdist,pfue);
       show_info(mode,dist,fue);
       printf("Enter 0 for metric mode,1 for US mode");
       printf("(-1 to quit):");
       scanf("%d",&mode);
      }
     printf("Loop times=%d\n",counts);      //And here
     puts("DONE!");

return 0;
}

int set_mode(int m,int *pprev)
{
   int mode;

if (m!=1&&m!=0)
    {mode=*pprev;
     printf("Invalid mode specified.MODE %s used.\n",mode==0?"0(metric)":"1(US)");}
else 
    {mode=m;
    *pprev=m;}
return mode;
}

void get_info(int mode,double *pdist,double *pfue)
{
  printf("Enter distance travelled in %s:",mode==0?"kilometers":"miles");
  scanf("%lf",pdist);

  printf("Enter fuel consumed in %s:",mode==0?"liters":"gallon");
  scanf("%lf",pfue);
         counts++;    //here!

return;
}

void show_info(int mode,const double distance,const double fuel)
{   
     double cons;
   
     if (mode==0)
      cons=M0;
     else if(mode==1)
      cons=M1;

    printf("Fuel consumption is %.4g %s.\n",cons,mode==0?MA0:MA1);

return;
}







