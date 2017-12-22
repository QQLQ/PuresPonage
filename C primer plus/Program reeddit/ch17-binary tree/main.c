#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include"list.h"

void showchoice(void);
void showitem(ITEM item);
char* sgets(char* line,int size);
void additem(TREE* ptree,ITEM*pi);
void deleteitem(TREE* ptree,ITEM*pi);
void showtree(TREE* ptree);

int main(void)
{
   TREE pet;
   ITEM temp;
   char ch;

   Initialize(&pet);

   while (showchoice(),scanf("%c",&ch))
   {
    while (getchar()!='\n');
    
    switch(ch)
     {
      case 'a':additem(&pet,&temp);continue;
      case 'd':deleteitem(&pet,&temp);continue;
      case 's':showtree(&pet);continue;
      case 'q':printf("BYE!\n");break;
      default:printf("Invalid input.Please enter again.\n");continue;
     }
     break;
    }
DeleteAll(&pet);
return 0;
}
char* sgets(char* line,int size)
{
   char*pt,*p;
   pt=fgets(line,size,stdin);
   p=line;
   if (pt)
     {
      while (*p!='\n'&&*p!='\0')
       p++;
      if (*p='\n')
        *p='\0';
      else 
        while (getchar()!='\n');
      }
return pt;
}

void showitem(ITEM item)
{
  printf("petname:%s   petkind:%s \n",item.petname,item.petkind);
return;
}

void showtree(TREE* ptree)
{
  if (TreeIsEmpty(ptree))
    printf("No data\n");
  else
   { 
    Traverse(ptree,showitem);
    printf("%d items in total.\n",CountTheTree(ptree));    
     }
return;
}

void showchoice(void)
{
  puts("Welcome to the test part.");
  puts("Option are as following:");
  puts("a).add new item.");
  puts("d).delete item.");
  puts("s).show item.");
  puts("q).to quit.");
  puts("Now please enter your choice");
return;
}

void additem(TREE* ptree,ITEM*pi)
{
   if (TreeIsFull(ptree))
     {
      printf("The tree is already full.Unable to add item.Please delete first.\n");
      return;
     }
   puts("Please enter the name of the pet.");
   while (sgets(pi->petname,NSIZE)!=NULL&&(pi->petname[0]!='\0') )
     {
      printf("Now please enter the kind for %s\n",pi->petname);
      if (sgets(pi->petkind,NSIZE)==NULL||pi->petkind[0]=='\0')
        break;
      if (false==AddItem(ptree,pi))
       {
        printf("Error adding item.Go back to main menu\n");
        break;
       }
      puts("Please now enter the next name for pet.(Press empty line to quit)");
     }
}





void deleteitem(TREE* ptree,ITEM*pi)
{
   if (TreeIsEmpty(ptree))
     {
      printf("The tree is Empty.Unable to add item.Please delete first.\n");
      return;
     }
   puts("Please enter the name of the pet.");
   while (sgets(pi->petname,NSIZE)!=NULL&&(pi->petname[0]!='\0') )
     {
      printf("Now please enter the kind for %s\n",pi->petname);
      if (sgets(pi->petkind,NSIZE)==NULL||pi->petkind[0]=='\0')
        break;
      if (false==DeleteItem(ptree,pi))
       {
        printf("Error deleting item.Go back to main menu\n");
        break;
       }
      puts("Please now enter the next name for pet.(Press empty line to quit)");
     }
}
