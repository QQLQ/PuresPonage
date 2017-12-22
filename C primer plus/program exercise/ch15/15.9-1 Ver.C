#include<stdio.h>

int btoi(char*);

int main(void)
{
  char *pbin="01001001";

printf("%d\n",btoi(pbin));

return 0;
}

int btoi(char* pbin)
{
   char *p;
   int tot=0;
   p=pbin;

   while (*p)
    {
    tot<<=1;
    tot|=*p++-'0';
    }

return tot;
}
