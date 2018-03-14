#include<iostream>
#include<string>
#include"emp.h"

using std::cout;
using std::cin;
using std::endl;
using std::string;

abstr_emp::abstr_emp()
{
 fname="Unit_f";
 lname="Unit_l";
 job="Unit_j";
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
 string temp_f,temp_l,temp_j;
 cout<<"Please enter the first name:";
 getline(cin,temp_f);
 if (temp_f=="")
   return;
 cout<<"Please enter the last name:";
 getline(cin,temp_l);
 if (temp_l=="")
   return;
 cout<<"Please enter the job:";
 getline(cin,temp_j);
 if (temp_j=="")
   return; 
 fname=temp_f;
 lname=temp_l;
 job=temp_j;
 return;
}
void abstr_emp::writeall(std::ostream &os)
{
os<<fname<<endl;
os<<lname<<endl;
os<<job<<endl;
}

std::ostream& operator<<(std::ostream &os,const abstr_emp&e)
{
 os<<e.fname<<" "<<e.lname<<":"<<e.job;
 return os;
}

abstr_emp::~abstr_emp(){}
employee::employee():abstr_emp(){}
employee::employee(const std::string& fn,const std::string& ln,const std::string& j):
abstr_emp(fn,ln,j){}
void employee::ShowAll()const
{
 abstr_emp::ShowAll();
}
void employee::SetAll()
{
 abstr_emp::SetAll();
}  
void employee::writeall(std::ostream &os)
{
 os<<Employee<<endl;
 abstr_emp::writeall(os);
}
manager::manager():abstr_emp(){}
manager::manager(const std::string &fn,const std::string & ln, const std::string &j,int ico):
   abstr_emp(fn,ln,j),inchargeof(ico){}
manager::manager(const abstr_emp& e,int ico):abstr_emp(e),inchargeof(ico){}
manager::manager(const manager&m):abstr_emp(m),inchargeof(m.inchargeof){}
void manager::ShowAll()const
{
 abstr_emp::ShowAll();
 cout<<"Inchargeof:"<<inchargeof<<endl;
}
void manager::SetAll()
{
 abstr_emp::SetAll();
 cout<<"Please enter number of inchargeof:";
 int temp_ico;
 cin>>temp_ico;
 if (cin.bad())
 { 
  cin.clear();
  while (cin.get()!='\n');
  return;
 }
 while(cin.get()!='\n');
 inchargeof=temp_ico;
 return;
}
void manager::writeall(std::ostream &os)
{
 os<<Manager<<endl;
 abstr_emp::writeall(os);
 os<<inchargeof<<endl;
}
fink::fink():abstr_emp(){}
fink::fink(const std::string&fn,const std::string&ln,const std::string& j,const std::string &rpo):
   abstr_emp(fn,ln,j),reportsto(rpo){}
fink::fink(const abstr_emp&e, const std:: string& rpo):abstr_emp(e),reportsto(rpo){}
fink::fink(const fink& e):abstr_emp(e),reportsto(e.reportsto){}
void fink::ShowAll() const
{
 abstr_emp::ShowAll();
 cout<<"reportsto:"<<reportsto<<endl;
}
void fink::SetAll()
{
 abstr_emp::SetAll();
 cout<<"Please enter rpo:";
 getline(cin,reportsto);
}
void fink::writeall(std::ostream &os)
{
  os<<Fink<<endl;
  abstr_emp::writeall(os);
  os<<reportsto<<endl;
}
highfink::highfink():abstr_emp(),manager(),fink(){}
highfink::highfink(const std::string& fn,const std::string& ln, const std::string & j,
          const std::string& rpo,int ico):
  abstr_emp(fn,ln,j),manager(fn,ln,j,ico),fink(fn,ln,j,rpo){}
highfink::highfink(const abstr_emp& e,const std::string& rpo,int ico):abstr_emp(e)
{
 fink::ReportsTo()=rpo;
 manager::InChargeOf()=ico;
}
highfink::highfink(const fink&f,int ico):abstr_emp(f),fink(f){manager::InChargeOf()=ico;}
highfink::highfink(const manager&m,const std::string &rpo):abstr_emp(m),manager(m)
{
  fink::ReportsTo()=rpo;
}
highfink::highfink(const highfink& h):
   abstr_emp(h),fink(h),manager(h){}
void highfink::ShowAll()const
{
  manager::ShowAll();
  cout<<"reportsto:"<<fink::ReportsTo()<<endl;
}
void highfink::SetAll()
{
 abstr_emp::SetAll();
 cout<<"Please enter number of inchargeof:";
 int temp_ico;
 cin>>temp_ico;
 if (cin.bad())
 { 
  cin.clear();
  while (cin.get()!='\n');
  return;
 }
 while(cin.get()!='\n');
 manager::InChargeOf()=temp_ico;
 cout<<"Please enter rpo:";
 getline(cin,fink::ReportsTo());
 return;
}
void highfink::writeall(std::ostream &os)
{
  os<<Highfink<<endl;
  abstr_emp::writeall(os);
  os<<(manager::InChargeOf())<<endl;
  os<<(fink::ReportsTo())<<endl;
}
