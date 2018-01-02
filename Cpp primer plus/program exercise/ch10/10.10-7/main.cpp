#include<iostream>
#include"plorg.h"

int main(void)
{
   using namespace std;
   plorg test1;
   test1.show();
   test1=plorg("MR X",100);
   test1.show();
   test1.setCI(12);
   test1.show();
   plorg test2("HHH",28);
   test2.show();
   return 0;
}
