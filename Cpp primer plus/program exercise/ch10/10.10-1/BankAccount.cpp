#include<iostream>
#include<string>
#include"BankAccount.h"

BankAccount::BankAccount()
{ 
  m_name="Error_m_Name";
  m_account="Error_m_account";
  m_saving=0;
}

BankAccount::BankAccount(const std::string name,const std::string account,const double saving)
{ 
  using std::cout;
  if (name=="")
   {
    cout<<"The name was not given.Set name to _Empty_Name\n";
    m_name="_Empty_Name";
   }
  else
    m_name=name;
    m_account=account;
    m_saving=saving;
}
void BankAccount::Show(void) const
{
 using std::cout;
 cout<<m_name<<"'s account info:\n";
 cout<<"Account number:"<<m_account<<"\n";
 cout<<"saving:"<<m_saving<<"\n";
 return;
}
void BankAccount::SaveMoney(double cash)
{
 using std::cout;
 m_saving+=cash;
 std::ios_base::fmtflags fmt_inital=cout.setf(std::ios_base::fixed,std::ios_base::floatfield);
 cout.precision(2);
 cout<<"$"<<cash<<" added,the saving is now $"<<m_saving<<".\n";
 cout.setf(fmt_inital);
 return;
}
void BankAccount::WithdrawMoney(double cash)
{
 using std::cout;
 std::ios_base::fmtflags fmt_inital=cout.setf(std::ios_base::fixed,std::ios_base::floatfield);
 cout.precision(2);
 if (cash>m_saving)
   cout<<"The balance is not enough. $"<<m_saving<<" in account.\n";
 else
 {
   m_saving-=cash;
   cout<<"$"<<cash<<" withdrawn,the saving is now $"<<m_saving<<".\n";
 }
 cout.setf(fmt_inital);
 return;
}
