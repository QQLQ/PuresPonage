#include<stdio.h>
void larger_of(double*px,double*py)
{
   double x=*px;
   double y=*py;

*px=*py=(x>y?x:y);

return;
}
