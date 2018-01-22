#include<iostream>
using namespace std;
#include"emp.h"

int main(void)
{
  employee em("Trip","Harries","Thumper");
  cout<<em<<endl;
  em.ShowAll();
  manager ma("Amorphia","Spindragon","Nuancer",5);
  cout<<ma<<endl;
  ma.ShowAll();
  fink fi("Matt","Oggs","oiler","Juno Barr");
  cout<<fi<<endl;
  fi.ShowAll();
  highfink hf(ma,"Curly kew");
  hf.ShowAll();
  cout<<"press a key for next phase:\n";
  cin.get();
  highfink hf2;
  hf2.SetAll();
  
  cout<<"Using an abstr_emp* pointer:\n";
  abstr_emp * tri[4]={&em,&fi,&hf,&hf2};
  for (int i=0;i<4;i++)
    tri[i]->ShowAll();

/*cout<<"Using an abstr_emp* pointer:\n";
  abstr_emp  tri[4]={em,fi,hf,hf2};
  for (int i=0;i<4;i++)
    tri[i].ShowAll();
*/
  return 0;

}

/*
  Q1:why no =defined?
  A1:No dynamic allocaton of memorary for member data.
  
  Q2:Why SetAll and ShowAll() defined virtual?
  A2:Dynamic binding, we need function to be determined by object themselves instread of pointer type or reference type.
  
  Q3:Why abstr_emp virtual?
  A3:Since we need one "fname,lname,job" instead of two.However fink and manager both inherit from
abstr_emp.If not defined virtual ,then we got two portions of "name and job",which we dont need,might cause confusion.
  Q4:Why no data session in highfink?
  A4:It mi from manager and fink.And the data in these two classes is exactly what highfink need.We
can use their data.So we dont have other data if we dont need.
  Q5:Why only one version of << function?
  A5:<< is a friend function,which can't be virtual or let's say it cant be dynamic binding by 
objects.Then we use dynameic binding no matter what versions it may have, function calling will be 
determind by pointer type of reference type. So we do not waste time and space defining more 
versions. However,it is ok to be determined by more versions for overloading if you want.As long as
you forget dynamic binding.
  Q6:What will happen?
  A6:Error,element of tri[4] is abstract base class object, which are not allowed to be 
instantiationed.
*/
