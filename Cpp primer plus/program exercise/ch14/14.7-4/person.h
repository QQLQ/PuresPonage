#ifndef PERSON_H_
#define PERSON_H_

#include<string>
#include<cstring>

class Person
{
private:
  std::string fname;
  std::string lname;
protected:
  virtual void Data();
public:
  Person(){fname="Nofname";lname="Nolname";}
  Person(const char*fn,const char*ln);
  Person(std::string fn,std::string ln);
  virtual ~Person(){}
  virtual void Show();
};



class Gunslinger:virtual public Person
{
private:
  double draw;
  int marks;
protected:
  virtual void Data();
public:
  Gunslinger(double dr,int ma,const char *fn,const char* ln):
  draw(dr),marks(ma),Person(fn,ln){}
  Gunslinger(double dr=-1.0,int ma=-1,std::string fn="Nofname",std::string ln="Nolname"):
  draw(dr),marks(ma),Person(fn,ln){}
  virtual ~Gunslinger(){}
  virtual void Show();
  virtual double Draw(){return draw;}  
};

class Card
{
public:
  Card(int su,int val){suit=su%4;value=value%13+1;}
  ~Card(){}
  void Show();
private:
  static const char* suits[4];
  int suit;
  int value;
};

class PokerPlayer:virtual public Person
{
public:
  PokerPlayer(const char *fn="Nofname",const char* ln="Nolname"):Person(fn,ln){}
  PokerPlayer(std::string fn,std::string ln):Person(fn,ln){}
  virtual ~PokerPlayer(){}
  virtual Card Draw();
  virtual void Show();
};

class BadDude:public PokerPlayer,public Gunslinger
{
public:
   BadDude():PokerPlayer(),Gunslinger(),Person(){}
   BadDude(double dr,int ma,const char *fn="Nofname",const char* ln="Nolname"):
   Gunslinger(dr,ma,fn,ln),PokerPlayer(fn,ln),Person(fn,ln){}
   BadDude(double dr=-1.0,int ma=-1,std::string fn="Nofname",std::string ln="Nolname"):
   Gunslinger(dr,ma,fn,ln),PokerPlayer(fn,ln),Person(fn,ln){}
   double Gdraw(){return Gunslinger::Draw();}
   Card Cdraw(){return PokerPlayer::Draw();}
   void Show();
};
   
#endif
