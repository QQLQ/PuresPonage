#include<stdio.h>
#include<stdlib.h>
#include"diceroll.h"

extern int ent(int dice,int sides);

int main(void)
{
    int  dice,sides,sets,res,i;
    int *ar;
printf("Enter the number of sets(Enter q to stop):");
while (scanf("%d",&sets)==1)
    {    ar=(int*)malloc(sets*sizeof(int));
         
         printf("How many sides and dice?");
         scanf("%d %d",&sides,&dice);
         res=ent(dice,sides);
         if (res==-2||res==-1)
             return 0;  
         printf("Here are %d sets of %d %d-sided throws.\n",sets,dice,sides);
         for (i=0;i<sets;i++)
            {printf("%3d",ent(dice,sides));
             if ((i+1)%15==0)
                putchar('\n');
            }            

        free(ar);
             if ((i+1)%15!=0)
                putchar('\n');
       
printf("How many sets?Enter q to stop:");
     }

puts("Bye!");

return 0;
}
