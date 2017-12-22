#include<stdio.h>
void SEQUE(double*pa,double*pb,double*pc)
{
  double a,b,c;
  
  a= *pa<*pb?*pa:*pb;
     if (a>*pc)
       a=*pc;

  c= *pa>*pb?*pa:*pb;
     if (c<*pc)
       c=*pc;
 
 if (*pa>a&&*pa<c)
     b=*pa;

 if (*pb>a&&*pb<c)
     b=*pb;
 
 if (*pc>a&&*pc<c)
     b=*pc; 
  
 *pa=a;
 *pb=b;
 *pc=c;        
  
return;
}
