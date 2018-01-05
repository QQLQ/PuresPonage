#include<iostream>
#include"Stonewt.h"

Stonewt::Stonewt()
{
 stone=pds_left=pounds=0;
 mode=stones;
}
Stonewt::Stonewt(double lbs,Mode form)
{
  if (lbs<0)
  {
  std::cout<<"Lbs can not be negative,set to 0\n";
  lbs=0;
  }
  mode=form;
  if (mode!=stones&&mode!=pounds_int&&mode!=pounds_fp)
  {
    std::cout<<"Invalid mode.Set to stone form\n";
    mode=stones;
  }
  pounds=lbs;
  stone=(int)lbs/Lbs_per_stn;
  pds_left=lbs-stone*Lbs_per_stn;
 }
Stonewt::Stonewt(int stn,double lbs,Mode form)
{
  if (stn<0||lbs<0)
  {
  std::cout<<"Neither can be negative,both set to 0\n";
  stn=lbs=0;
  }
  mode=form;
  if (mode!=stones&&mode!=pounds_int&&mode!=pounds_fp)
  {
    std::cout<<"Invalid mode.Set to stone form\n";
    mode=stones;
  }
  pounds=stn*Lbs_per_stn+lbs;
  stone=(int)pounds/Lbs_per_stn;
  pds_left=pounds-stone*Lbs_per_stn;
}
Stonewt Stonewt::operator+(const Stonewt&s) const
{
 return Stonewt(stone+s.stone,pds_left+s.pds_left);
}
Stonewt Stonewt::operator-(const Stonewt&s) const
{
 return Stonewt(stone-s.stone,pds_left-s.pds_left);
}
Stonewt Stonewt::operator*(double n) const
{
 return Stonewt(stone*n,pds_left*n);
}
Stonewt operator*(double n,const Stonewt&s)
{
 return Stonewt(s.stone*n,s.pds_left*n);
}
std::ostream& operator<<(std::ostream& os,const Stonewt&s)
{
  switch (s.mode)
  {
   case Stonewt::stones: os<<s.stone<<" stone,"<<s.pds_left<<" pounds\n";break;
   case Stonewt::pounds_int:os<<(int)s.pounds<<" pounds\n";break;
   case Stonewt::pounds_fp:os<<s.pounds<<" pounds\n";break;
   default:os<<"Invalid mode.Check the program.\n";break;
   }
   return os;
}
