#include<stdio.h>
void SEQUE(double*,double*,double*);
int main(void)
{
  double a,b,c;
  
  printf("Plz enter the first of 3 numbers:");
  while (scanf("%lf",&a)!=1)
     {scanf("%*s");
      printf("Reenter plz:");}

  printf("Plz enter the second of 3 numbers:");
  while (scanf("%lf",&b)!=1)
     {scanf("%*s");
      printf("Reenter plz:");}

  printf("Plz enter the last of 3 numbers:");
  while (scanf("%lf",&c)!=1)
     {scanf("%*s");
      printf("Reenter plz:");}

SEQUE(&a,&b,&c);

printf("From smallest to largest:,%g<%g<%g\n",a,b,c);

return 0;
}
