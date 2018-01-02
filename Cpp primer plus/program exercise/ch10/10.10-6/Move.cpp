#include<iostream>
#include"Move.h"

Move::Move(double a,double b)
{
   x=a;
   y=b;
}

void Move::showmove() const
{
 std::cout<<"x="<<x<<" ,y="<<y<<std::endl;
 return;
}

Move Move::add(const Move& m) const
{
 return Move(m.x+x,m.y+y);
}

void Move::reset(double a,double b)
{
 x=a;
 y=b;
 return;
}
