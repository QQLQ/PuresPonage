#ifndef _BankAccount_h
#define _BankAccount_h
#include<string>

class BankAccount{
  private:
  std::string m_name;
  std::string m_account;
  double m_saving;
  public:
  BankAccount();
  BankAccount(const std::string name,const std::string account,const double saving);
  void Show(void) const;
  void SaveMoney(double cash);
  void WithdrawMoney(double cash);
  };
  
#endif
