#include<iostream>
#include<string>
#include"emp.h"

using std::cout;
using std::cin;
using std::endl;
using std::string;

abstr_emp::abstr_emp()
{
  fname="Nof_abstr_emp";
  lname="Nol_abstr_emp";
  job="Noj_abstr_emp";
}
abstr_emp::abstr_emp(const std::string &fn,const std::string &ln,const std::string &j)
{
  fname=fn;
  lname=ln;
  job=j;
}
void abstr_emp::ShowAll() const
{
  cout<<"Name:"<<fname<<" "<<lname<<endl;
  cout<<"Job:"<<job<<endl;
}  
void abstr_emp::SetAll()
{
  cout<<"Enter first name:";
  getline(cin,fname);
  cout<<"Enter last name:";
  getline(cin,lname);
  cout<<"Enter job:";
  getline(cin,job);
}
std::ostream& operator<<(std::ostream &os,const abstr_emp&ra)
{
  os<<"name:"<<ra.fname<<" "<<ra.lname<<" with job of "<<ra.job;
  return os;
} 
abstr_emp::~abstr_emp(){}

employee::employee():abstr_emp("Nof_e","Nol_e","Noj_e"){}
employee::employee(const std::string& fn,const std::string& ln,const std::string& j):
abstr_emp(fn,ln,j){}
void employee::ShowAll()const
{
 cout<<"Employee's data:"<<endl;
 abstr_emp::ShowAll();
}
void employee::SetAll()
{
 cout<<"Please reset data for employee:";
 abstr_emp::SetAll();
}

manager::manager():abstr_emp("Nof_m","Nol_m","Noj_m"),inchargeof(0){}
manager::manager(const std::string &fn,const std::string & ln, const std::string &j,int ico)
:abstr_emp(fn,ln,j),inchargeof(ico){}
manager::manager(const abstr_emp& e,int ico):abstr_emp(e),inchargeof(ico){}
manager::manager(const manager&m):abstr_emp(m),inchargeof(m.inchargeof){}
void manager::ShowAll()const
{
  cout<<"Manager's data:"<<endl;
  abstr_emp::ShowAll();
  cout<<"Inchargeof:"<<inchargeof<<endl;
}
void manager::SetAll()
{
  cout<<"Set for Manager's data:";
  abstr_emp::SetAll();
  cout<<"Set for inchargeof:";
  cin>>inchargeof;
  while (cin.get()!='\n');
}

fink::fink():reportsto("No_set"){}
fink::fink(const std::string&fn,const std::string&ln,const std::string& j,const std::string &rpo):
abstr_emp(fn,ln,j),reportsto(rpo){}
fink::fink(const abstr_emp&e, const std:: string& rpo):abstr_emp(e),reportsto(rpo){}
fink::fink(const fink& e):abstr_emp(e),reportsto(e.reportsto){}
void fink::ShowAll() const
{
 cout<<"Fink's data:"<<endl;
 abstr_emp::ShowAll();
 cout<<"reportsto:"<<reportsto<<endl;
}
void fink::SetAll()
{
 cout<<"Set for Fink"<<endl;
 abstr_emp::SetAll();
 cout<<"Set for reportsto:"<<endl;
 getline(cin,reportsto);
}
 
highfink::highfink(){}
highfink::highfink(const std::string& fn,const std::string& ln, const std::string & j,
const std::string& rpo,int ico):abstr_emp(fn,ln,j),manager(fn,ln,j,ico),fink(fn,ln,j,rpo){}
highfink::highfink(const abstr_emp& e,const std::string& rpo,int ico):abstr_emp(e),manager(e,ico),fink(e,rpo){}
highfink::highfink(const manager&m,const std::string &rpo):manager(m),fink(m,rpo),abstr_emp(m){}
highfink::highfink(const fink&f,int ico):fink(f),manager(f,ico),abstr_emp(f){}
highfink::highfink(const highfink& h):fink(h),manager(h),abstr_emp(h){}
void highfink::ShowAll()const
{
  cout<<"Highfink's data:"<<endl;
  abstr_emp::ShowAll();
  cout<<"inchargeof:"<<manager::InChargeOf()<<endl;
  cout<<"reportsto:"<<fink::ReportsTo()<<endl;
}
void highfink::SetAll()
{
  cout<<"Set for highfink:"<<endl;
  abstr_emp::SetAll();
  cout<<"Now set for ico:";
  cin>>InChargeOf();
  while (cin.get()!='\n');
  cout<<"Now set for rpo:";
  getline(cin,fink::ReportsTo());
}  
