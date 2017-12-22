#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"diceroll.h"

int roll_count;

int ent(int dice,int sides);
int roll(int side);

int roll(int sides)
{   int roll;
    srand(roll_count+(int)time(NULL));
    roll= rand()%sides+1;
    return roll;
}

int ent(int dice,int sides)
{   int total=0;
    if (sides<2)
      {puts("There must be at least 2 sides of the dice.");
       return -2;
       }

    if (dice<1)
      {puts("There must be at least 1 dice.");
       return -1;
       }
roll_count++;
     for (int i=0;i<dice;i++)
       total+= roll(sides);

return total;
}

