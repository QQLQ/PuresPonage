#include<iostream>
#include<fstream>
#include<string>
#include<cstdlib>
#include"emp.h"

const int MAX=10;
const char tar_file[]="cla.dat";
int main(int argc,char** argv)
{
 using std::cout;
 using std::cin;
 using std::cerr;
 using std::ifstream;
 using std::ofstream;
 using std::endl;
 using std::ios_base;
 using std::string;
 
 if (argc!=1)
 {
  cout<<"Automatic!"<<endl;
  std::exit(1);
 }
 
 abstr_emp *pc[MAX];
 ifstream fin(tar_file);
 if (!(fin.is_open()))
 {
  cout<<"Unable to open file[in]"<<endl;
  exit(1);
 }  
 fin.seekg(0);
 int classtype;
 string fname,lname,job,rpo;
 int ico;
 char ch;
 int items=0;
 while ((fin>>classtype).get(ch))
 {    
   if (items==0)
     cout<<"Saved items:"<<endl;
   getline(fin,fname);getline(fin,lname);getline(fin,job);
   switch(classtype)
   {
    case Employee:
         pc[items]=new employee(fname,lname,job);break;
    case Manager:
         (fin>>ico).get(ch);
         pc[items]=new manager(fname,lname,job,ico);break;
    case Fink:
         getline(fin,rpo);
         pc[items]=new fink(fname,lname,job,rpo);break;
    case Highfink:
         (fin>>ico).get(ch);
         getline(fin,rpo);
         pc[items]=new highfink(fname,lname,job,rpo,ico);break;
    }
    cout<<"No."<<items+1<<":"<<endl;
    pc[items++]->ShowAll();
  }
  fin.clear();
  fin.close();
  ofstream fout(tar_file,ios_base::out|ios_base::app);
  if (!(fout.is_open()))
  {
   cout<<"Unable to open file[out]"<<endl;
   exit(1);
  }  
 if (items>=10)
 {
   cout<<"Items reached the max szie."<<endl;
   exit(0);
 }
 else
 {
  while (items<MAX)
  {
  cout<<"Please enter the class you wanna created."<<endl;
  cout<<"0.Employee 1.Manager 2.Fink 3.Highfink Or other to quit:"<<endl;
  cin>>classtype;
  if (cin.bad())
     {
      cin.clear();
      classtype=-1;
     }
  while(cin.get()!='\n');
  if (!(Employee<=classtype&&classtype<=Highfink))
    break;
  cout<<"Please enter fname:"<<endl;
  getline(cin,fname);
  cout<<"Please enter lname:"<<endl;
  getline(cin,lname);
  cout<<"Please enter job:"<<endl;
  getline(cin,job);
  switch(classtype)
   {
    case Employee:
         pc[items]=new employee(fname,lname,job);break;
    case Manager:
         cout<<"Please enter ico:";
         cin>>ico;
         while (cin.get()!='\n');
         pc[items]=new manager(fname,lname,job,ico);break;
    case Fink:
         cout<<"Please enter rpo:";
         getline(cin,rpo);
         pc[items]=new fink(fname,lname,job,rpo);break;
    case Highfink:
         cout<<"Please enter ico:";
         cin>>ico;
         while (cin.get()!='\n');
         cout<<"Please enter rpo:";
         getline(cin,rpo);
         pc[items]=new highfink(fname,lname,job,rpo,ico);break;
    }
    pc[items]->writeall(fout);
    items++;
   }
  }
  if(items==10)
  {
   cout<<"Size reached MAX"<<endl;
  }
  for (int id=0;id<items;id++)
  {
   cout<<"No."<<id+1<<":"<<endl;
   pc[id]->ShowAll();
   cout<<endl;
  }
  fout.close();
  
  cout<<"Done"<<endl;
  
 return 0;
}
