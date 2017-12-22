#include"tree.h"
#include<stdio.h>
#include<string.h>
#include<ctype.h>

int petsize=0;  //I hate this.But i ran out of ideas.

char menu(void);
void addpet(TREE*ptree);
void droppet(TREE*ptree);
void showpet(TREE*ptree);
void findpet(TREE*ptree);
void printitem(ITEM item);
void uppercase(char*str);
char* sgets(char*line,int size);
void countitem(ITEM item);
void countpet(TREE*ptree);

int main(void)
{
  TREE pets;
  char choice;
  Initialize(&pets);

  while ((choice=menu())!='q')
   {
     switch(choice)
     {
      case'a':addpet(&pets);break;
      case'l':showpet(&pets);break;
      case'f':findpet(&pets);break;
      case'n':countpet(&pets);break;
      case'd':droppet(&pets);break;
      default: puts("Invalid input.");
     }
   }
   
  EmptyAll(&pets);
  puts("DONE!");
return 0;
}

void countpet(TREE*ptree)
{
 Traverse(ptree,countitem);
 printf("%d pets in club\n",petsize);
 petsize=0;
return;
}

void countitem(ITEM item)
{
 petsize+=item.showed;
}
char menu(void)
{
     int ch;
     puts("PET CLUB!");
     puts("Menu:");
     puts("a) add a pet       l) show list of pets");
     puts("n) number of pets  f) find pets");
     puts("d) delete a pet    q) quit");
     while ((ch=getchar())!=EOF)
     {
       while (getchar()!='\n');
       ch=tolower(ch);
       if (strchr("alrfndq",ch)==NULL)
           puts("Please enter an a,l,f,n,d or q");
       else 
           break;
     }
if (ch==EOF) 
 ch='q';
return ch;
}

void addpet(TREE*ptree)
{
  ITEM temp;
  
  if (TreeIsFull(ptree))
    puts("No room in the club.");
  else
   {
    puts("Please enter name of pet");
    sgets(temp.petname,CSIZE);
    puts("Please enter petkind");
    sgets(&temp.petkind[0][0],CSIZE);
    uppercase(temp.petname);
    uppercase(&temp.petkind[0][0]);
    AddItem(ptree,&temp);
    }
return;
}

void showpet(TREE* ptree)
{
  if(TreeIsEmpty(ptree))
    puts("No data.");
  else
    Traverse(ptree,printitem);
}

void printitem(ITEM item)
{
 int i;
 for (i=0;i<item.showed;i++)
  printf("Pet:%-19s kind:%-19s %d\n",item.petname,&item.petkind[i][0],item.showed);
}

void findpet(TREE*ptree)
{
 ITEM temp;
 if (TreeIsEmpty(ptree))
  {
    puts("No data");
    return;
  }
 
 puts("Please enter petname");
 sgets(temp.petname,CSIZE);
 puts("Please eneter petkind");
 sgets(&temp.petkind[0][0],CSIZE);
 uppercase(temp.petname);
 uppercase(&temp.petkind[0][0]);
 printf("%s the %s ",temp.petname,&temp.petkind[0][0]);
 if (InTree(ptree,&temp))
   printf("is a memeber.\n");
 else
   printf("is not a memeber.\n");
}

void droppet(TREE*ptree)
{
 ITEM temp;

  if (TreeIsEmpty(ptree))
    {
     puts("No data.");
     return;
    }

 puts("Please enter name of pet you wish to delete:");
 sgets(temp.petname,CSIZE);
 puts("Please enter petkind");
 sgets(&temp.petkind[0][0],CSIZE);
 uppercase(temp.petname);
 uppercase(&temp.petkind[0][0]);
 printf("%s the %s ",temp.petname,&temp.petkind[0][0]);
 if (DeleteItem(ptree,&temp))
    printf("is dropped from the club\n");
 else
    printf("is not a member.\n");
}

void uppercase(char*line)
{
  while (*line)
   {
    *line=toupper(*line);
    line++;
   }
}

char* sgets(char*line,int size)
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
