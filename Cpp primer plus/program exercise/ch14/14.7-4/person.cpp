#include<iostream>
#include<cstdlib>
#include<ctime>
#include"person.h"

//Person methods;

using std::cout;
using std::cin;
using std::endl;
using std::string;

Person::Person(const char*fn,const char*ln)
{
 fname=fn;
 lname=ln;
}
Person::Person(string fn,string ln)
{
 fname=fn;
 lname=ln;
}

void Person::Data()
{
  std::cout<<fname<<" "<<lname;
}

void Person::Show()
{
  cout<<"Person's name:";
  Data();
}
//Gunslinger Data;

void Gunslinger::Data()
{
  cout.precision(2);
  cout<<"Draw:"<<draw<<endl;
  cout<<"Marks:"<<marks<<endl;
}
void Gunslinger::Show()
{
  cout<<"Gunslinger's data:\n"<<"Name:";
  Person::Data();
  cout<<endl;
  Data();
}

const char* Card::suits[4]={"Spade","Heart","Club","Diamond"};

void Card::Show()
{
  cout<<"Card:"<<suits[suit]<<" "<<value<<endl;
}

Card PokerPlayer::Draw()
{
  srand(time(0));
  int value=rand();
  int suit=rand();
  Card temp(suit,value);
  return temp;
}

void PokerPlayer::Show()
{
  cout<<"PokerPlayer's data:"<<endl;
  Person::Data();
  cout<<endl;
}  

void BadDude::Show()
{
  cout<<"BadDude's Name:";
  Person::Data();
  cout<<endl;
  Gunslinger::Data();
}
