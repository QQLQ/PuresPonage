#include"tree.h"
#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define FSIZE 31

char* sgets(char*line,int size);
FILE* openfile(void);
char getchoice(void);
void showoption(TREE*ptree);
void showword(ITEM item);
void findoption(TREE*ptree,ITEM*pi);
void closefile(FILE*fp);
bool findword(FILE*fp,ITEM*pi);
void makestatics(TREE*ptree,ITEM*pi,FILE*fp);

int main(void)
{
  TREE article;
  FILE* fp;
  ITEM temp;
  fp=openfile();
  Initialize(&article);

  if (!TreeIsEmpty(&article))
  {
   fprintf(stderr,"Faild to initialize tree.\n");
   exit(EXIT_FAILURE);
  }

  makestatics(&article,&temp,fp);
  closefile(fp);

  while (1)
  {
    switch(getchoice())
     { 
      case 's':showoption(&article);continue;
      case 'f':findoption(&article,&temp);continue;
      case 'q':break;
      }
    break;
   }
EmptyAll(&article);
puts("Bye!");
return 0;
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
FILE* openfile(void)
{
 char name[FSIZE];
 FILE*fp;
 puts("Please eneter the name of the file you wanna search.");
 while(1)
{
  if (sgets(name,FSIZE)==NULL||name[0]=='\0')
   {
    puts("Invalid input.Please eneter again.");
    continue;
   }
   fp=fopen(name,"r");
  if (fp==NULL)
   {
    fprintf(stderr,"Failed to open file \"%s\"\n,please enter again.",name);
    continue;
   }
  return fp;
  }
}
  
char getchoice(void)
{
  char ch;
  printf("s)Show words  f)find word  q) quit\n");
  puts("Please enter your choice");
  while (scanf("%c",&ch),1)
   {
    while (getchar()!='\n');
    if (strchr("sfq",ch)==NULL)
     {
      fprintf(stderr,"No an option,enter again please\n");
      continue;
     }
    else
     return ch;
   }
}

void showoption(TREE*ptree)
{
 if (TreeIsEmpty(ptree))
  {
   printf("No data read from file.\n");
   return;
  }
 else
  {
   printf("Static as following:\n");
   Traverse(ptree,showword);
  printf("root:%s\n",ptree->root->item.word);   
  printf("%d words in total.\n",CountTheTree(ptree));
   }  
return;
}

void makestatics(TREE*ptree,ITEM*pi,FILE*fp)
{
 while (findword(fp,pi))
  {
   AddItem(ptree,pi);
   if(feof(fp))
     break;

   }
 return;
}

bool findword(FILE*fp,ITEM*pi)
{
 char ch;
 char line[CSIZE];
 int i;

 while (!isalnum(ch=getc(fp))&&ch!=EOF);
 if (ch==EOF)
    return false;
 for (i=0;i<CSIZE;i++)
 {
   line[i]=tolower(ch);
   ch=getc(fp);
   if (!isalnum(ch))
    break;
 }
  
 line[++i]='\0';
 strcpy(pi->word,line);
return true;
}
    
void findoption(TREE*ptree,ITEM*pi)
{
 puts("Please enter the word you wanna search.");
 if (sgets(pi->word,CSIZE),pi->word[0]!='\0')
  {
   if (InTree(ptree,pi))
     printf("Yes,%s is in and it showed up for %d times.\n",pi->word,pi->showed);
   else
     printf("%s is not in the tree.\n",pi->word);
  }
return;
}
    

void closefile(FILE*fp)
{
 fclose(fp);
return;
}

void showword(ITEM item)
{
  printf("Word:%s  Showed Up:%d\n",item.word,item.showed);
return;
}
