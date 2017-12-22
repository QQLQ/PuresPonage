#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include"list.h"

#define SSIZE 31
char* sgets(char* line,int size);
char showmenu(void);
void showstack(STACK*ps);
void enterstring(STACK*ps);
void deletestring(STACK*ps);
int main(void)
{
 STACK input;
 Initialize(&input);

 while (1)
 {
  switch (showmenu())
    {
     case 'a':enterstring(&input);continue;
     case 'd':deletestring(&input);continue;
     case 's':showstack(&input);continue;
     case 'q':break;
     }
   break;
 }

puts("DONE!");

return 0;
}

char* sgets(char* line,int size)
{
   char *pt,*find;
   pt=fgets(line,size,stdin);
   if (pt)
     {
      find=strchr(line,'\n');
      if (find)
         *find='\0';
      else
         while (getchar()!='\n');
      }
return pt;
}

void showstack(STACK*ps)
{
  int i;
  if (StackIsEmpty(ps))
    puts("No data");
  else 
    puts("Strings as following:");
    for (i=0;i<ps->top;i++)
      printf("No.%d:%s\n",i+1,ps->items[i]);
return;
}

void enterstring(STACK*ps)
{
 char temp[SSIZE]; 

 puts("Enter string please");
 while (sgets(temp,SSIZE)!=NULL&&temp[0]!='\0')
  {
   Push(ps,temp);
   if (StackIsFull(ps))
    { 
     printf("The stack is already full\n");
     break;
    }
   puts("Please enter next strings.");
  }
return;
}

char showmenu(void)
{
  char ch;
  printf("Menu:\n");
  printf("a) Add str.  d) delete str.\n");
  printf("s) show str. q) quit.\n");
  puts("Please enter your choice");

  while (scanf("%c",&ch)!=1||strchr("adsq",ch)==NULL)
  {
   while (getchar()!='\n');
   puts("Please reenter your choice.");
  }
  while (getchar()!='\n');

return ch;
}

void deletestring(STACK*ps)
{
 char *temp; 
 
 if ( Pop(ps,&temp) )
  {
   printf("string \"%s\" deleted.\n",temp);
   free(temp);
   }
return;
}
