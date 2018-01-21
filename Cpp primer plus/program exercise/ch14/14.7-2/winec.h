#ifndef WINE_H_
#define WINE_H_

#include<iostream>
#include<string>
#include<valarray>

//Pairs: template class
template<class T1,class T2>
class Pair
{
private:
  T1 a;
  T2 b;
public:
  T1& first();
  T2& second();
  T1 first() const{return a;}
  T2 second() const{return b;}
  Pair(const T1& aval, const T2& bval):a(aval),b(bval){}
  Pair(){}
};

template<class T1,class T2>
T1& Pair<T1,T2>::first()
{
 return a;
}

template<class T1,class T2>
T2& Pair<T1,T2>::second()
{
 return b;
}

//wine: class
typedef std::valarray<int> ArrayInt;
typedef Pair<ArrayInt,ArrayInt> PairArray;

class Wine:private Pair<ArrayInt,ArrayInt>,private std::string
{
private:
  int years;
public:
  Wine();
  Wine(const char* l,int y,const int yt[],const int bot[]);
  Wine(const char*l,int y);
  void GetBottles();
  const std::string& Label();
  int sum();
  void show();
};

#endif
