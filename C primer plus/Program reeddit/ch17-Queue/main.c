#include"queue.h"
#include<stdio.h>
#include<stdlib.h>

void showqueue(ITEM item)
{
 printf("Name:%s, Age:%d\n",item.name,item.age);
return;
}

char* sgets(char*line,int size)
{
  char *pt,*p;
  pt=fgets(line,size,stdin);
  p=line;
  if (pt)
   {
    while (*p!='\n'&&*p!='\0')
       p++;
    if (*p=='\n')
       *p='\0';
    else
      while (getchar()!='\n');
   }
return pt;
}
  
int main(void)
{
 ITEM temp;
 QUEUE person;
 Initialize(&person);
 char ch;
while (puts("Please enter your choice."),(ch=getchar())!='q'){
while (getchar()!='\n'); 
 if (ch!='a'&&ch!='d')
    continue;
if (ch=='a'){
 puts("please enter the name");

 while (sgets(temp.name,NSIZE)!=NULL&&temp.name[0]!='\0'){
   printf("Now please enter the age for %s\n",temp.name);
   if (scanf("%d",&temp.age)!=1){
      while (getchar()!='\n');
      puts("Invalid input.Go back to input name:\n");
      continue;
      }
   while (getchar()!='\n');

   if (false==AddItem(&person,temp)){
     fprintf(stderr,"Problem allocating memory");
     break;
     }
   printf("%d items in total\n",CountTheQueue(&person));

   if (true==QueueIsFull(&person)){
     fprintf(stderr,"Queue is full\n");
     break;
     }   
   break;
  }
}
else{

   if (true==QueueIsEmpty(&person)){
     printf("No data \n");
     continue;
     }
   else {
     printf("Queue are as following:\n");
     Traverse(&person,showqueue);
     }

printf("%s removed.\n",person.front->item.name);
   DeleteTheQueue(&person);

   if (true==QueueIsEmpty(&person)){
     printf("\nNo data left now\n");
     }
   else {
     printf("Queue now are as following:\n");
     Traverse(&person,showqueue);
     }
   }
}
  
EmptyTheQueue(&person);
puts("Bye");    
return 0;
}  
