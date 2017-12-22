#include<stdio.h>
void larger_of(double *,double *);
int main(void)
{  double x,y;

   printf("Please enter two doubles:");

  while (scanf("%lf %lf",&x,&y)!=2)
       {scanf("%*s");
        printf("Please reenter:");}

larger_of(&x,&y);;

printf("The numbers you entered are both %g,which is larger of the originals",x);

putchar('\n');

return 0;
}
