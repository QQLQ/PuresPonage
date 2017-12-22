#include<stdio.h>
#include<ctype.h>
long getlong(int t);                         //get and check if it is long
int LIMIT(long a,long b,long MIN,long MAX);  //check if MIN<a<=b<MAX
double SUM(long a,long b);                   //compute the sums of squares(a to b)
int RETRY(void);                             //retry function,y to re,n to quit
int main(void)
{
RET: ;
    long a,b;                   //a<b
    double sumtotal;               //sum of squares
    int T=1;                    //test it is a, or b 
    int R;                         //for RETRY.tmporary 
    char ch;                    //Tempor test char,will be 0 after temp test
    const long MIN=-100000000;     //MIN number
    const long MAX=100000000;   //MAX number
    
   printf("Plz enter two integers,and be careful\n\
       a<b,a>MIN(MIN=-%ld),b<MAX(MAX=%ld)\n",MIN,MAX);
    a=getlong(T);
     T++;
    b=getlong(T);

    if ( LIMIT(a,b,MIN,MAX) )
      {printf("Unable to continue,");
           if ( RETRY()==1 )
              return 0;
           else 
              goto RET;
       }

      SUM(a,b);

printf("Done!\n");

if ( RETRY()==1 )
   return 0;
else 
   goto RET;
}

long getlong(int T)
{
   long i;
   char ch;
   printf("Please enter %c:_________\b\b\b\b\b\b\b\b\b",T==1?'a':'b');
   while ( scanf("%ld",&i)!=1 ) 
      { while ((ch=getchar())!='\n')    
             putchar(ch);
        printf(" is not an integer.Please enter again:");
         continue;
       }
   while ( getchar()!='\n' );
  return i;
}

int LIMIT(long a,long b,long MIN,long MAX)
{  int A,B,C,N;
       A=B=C=N=0;
   
   char QA[50]= "the numbers you entered must be greater than ";
   char QB[50]= "a must be smaller than b";
   char QC[50]= "the numbers you entered must be samller than ";

     if (a<MIN||b<MIN) A=1; 
     if (a>b)          B=1;
     if (a>MAX||b>MAX) C=1; 
       N=A+B+C;
     
     if (N>0)
     {
      printf("Invalid input,");
        if (A!=0) 
              printf("%s%ld",QA,MIN);        
        if (B!=0)
           {  if (A!=0) printf(",");
              printf("%s",QB);}
        if (C!=0)
            { if (A!=0||B!=0) printf(",and");
              printf("%s%ld",QC,MAX);}
        printf(".\n");
     }


      return N;
}
           



int RETRY(void)
{        
    char ch;
 

    printf("Retry?:");
            while (ch=getchar())
              {if (ch=='y')
                  return 2;
               if (ch=='n')
                  {printf("Ok,bye.\n");
                   return 1;}
               else 
                    {printf("Cant understand, enter again:");
                        while (getchar()!='\n');  
                        continue;}
                 }
}

double SUM(long a,long b)
{long i;
    double total=0;
       for (i=a;!(i>b);i++)
            total+=i*i;

     if (a>b) a=b;
printf("The sum of the suqares of the integers from %ld to %ld is \
%g.\n",a,b,total);

return total;
} 
