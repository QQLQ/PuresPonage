#include<stdio.h>
double HARM(double,double);
int main(void)
{
     double x,y;
   printf("Please enter two numbers and i will give you harmonic mean"
          "of the two numbers you entered:");

   while (scanf("%lf %lf",&x,&y)!=2)
       {scanf("%*s");
        printf("Plz reenter:");}

printf("The harmonic mean is %lf.\n",HARM(x,y));

return 0;
}
