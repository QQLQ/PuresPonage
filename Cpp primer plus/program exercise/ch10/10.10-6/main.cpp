#include<iostream>
#include"Move.h"

int main(void)
{
 Move test1;
 test1.showmove();
 Move test2(10,20);
 test2.showmove();
 test1.reset(15,28);
 test1.showmove();
 test2=test1.add(test2);
 test2.showmove();
 return 0;
}
