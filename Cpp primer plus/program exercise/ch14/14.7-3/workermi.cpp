#include"workermi.h"
#include<iostream>
using std::cout;
using std::cin;
using std::endl;

//Wroker methods
Worker::~Worker(){}

//protected methods
void Worker::Data() const
{
  cout<<"Name: "<<fullname<<endl;
  cout<<"Employee ID: "<<id<<endl;
}

void Worker::Get()
{
  getline(cin,fullname);
  cout<<"Enter Wroker's ID:";
  cin>>id;
  while (cin.get()!='\n');
}

//Waiter methods
void Waiter::Set()
{
  cout<<"Enter waiters's name: ";
  Worker::Get();
  Get();
}

void Waiter::Show() const
{
  cout<<"Category: waiter\n";
  Worker::Data();
  Data();
}

//protected methods
void Waiter::Data() const
{
  cout<<"Panche rating: "<<panche<<endl;
}

void Waiter::Get()
{
  cout<<"Enter waiter's panche rating:";
  cin>>panche;
  while (cin.get()!='\n');
}

//Singer methods;

char* Singer::pv[Singer::Vtypes]={"Other","alto","contrallo","soprano","bass","baritone","tenor"};

void Singer::Set()
{
  cout<<"Enter singer's name:";
  Worker::Get();
  Get();
}

void Singer::Show() const
{
  cout<<"Category singer\n";
  Worker::Data();
  Data();
}

//protected methods
void Singer::Data() const
{
  cout<<"Vocal range:"<<pv[voice]<<endl;
}

void Singer::Get()
{
  cout<<"Enter number for singer's vocal range:\n";
  int i;
  for (i=0;i<Vtypes;i++)
  {
    cout<<i<<": "<<pv[i]<<"  ";
    if (i%4==3)
      cout<<endl;
  }
  if (i%4!=0)
    cout<<endl;
  cin>>voice;
  while (cin.get()!='\n');
}

//SingerWaiter methods
void SingerWaiter::Data() const
{
  Singer::Data();
  Waiter::Data();
}    

void SingerWaiter::Get()
{
  Waiter::Get();
  Singer::Get();
}

void SingerWaiter::Set()
{
  cout<<"Enter singing waiter's name:";
  Worker::Get();
  Get();
}

void SingerWaiter::Show() const
{
  cout<<"Category: singing waiter\n";
  
  Worker::Data();
  Data();
}
