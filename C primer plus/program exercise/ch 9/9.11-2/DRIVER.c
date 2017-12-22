#include<stdio.h>
void chline(char,int,int);
int main(void)
{
int j,i;
char ch;

printf("Please enter the characters you wanna print:");
while (scanf("%c",&ch)!=1)
  {while (getchar()!='\n');
   printf("Please reenter:");}

printf("Please enter the lines you wanna print:");
while (scanf("%d",&j)!=1)
  {scanf("%*s");
   printf("Please reenter lines:");}

printf("Please enter the cols you wanna print:");
while (scanf("%d",&i)!=1)
  {scanf("%*s");
   printf("Please reenter cols:");}

PRI(ch,j,i);
return 0;
}
