#ifndef STONEWT_H_
#define STONEWT_H_
#include<iostream>

class Stonewt{
public:
  enum Mode{stones,pounds_int,pounds_fp};
private:
  enum {Lbs_per_stn=14};
  int stone;
  double pds_left;
  double pounds;
  Mode mode;
public:
  Stonewt();
  Stonewt(double lbs,Mode=stones);
  Stonewt(int stn,double lbs,Mode=stones);
  ~Stonewt(){};
  Stonewt operator+(const Stonewt&s) const;
  Stonewt operator-(const Stonewt&s) const;
  Stonewt operator*(double n) const;
  bool operator<(const Stonewt&s) const;
  bool operator<=(const Stonewt&s) const;
  bool operator>(const Stonewt&s) const;
  bool operator>=(const Stonewt&s) const;
  bool operator==(const Stonewt&s) const;
  bool operator!=(const Stonewt&s) const;
  friend Stonewt operator*(double n,const Stonewt&s) ;
  friend std::ostream& operator<<(std::ostream&os,const Stonewt&s);
};
#endif
