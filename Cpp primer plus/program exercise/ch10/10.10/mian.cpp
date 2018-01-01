#include<iostream>
#include<string>
#include"BankAccount.h"

int main(void)
{
  using std::cout;
  using std::cin;
  using std::endl;
  using std::string;
  
  class BankAccount test;
  string name;
  string account;
  double cash;  
  char ch;
  
  test.Show();
  cout<<"Test:\n"<<"Please now enter the name:\n";
  getline(cin,name);
  cout<<"Now please enter the account number.\n";
  getline(cin,account);
  cout<<"Enter the saving please.\n";
  cin>>cash;
  while (!cin.good())
  {
   cin.clear();
   while (cin.get()!='\n');
   cout<<"Invalid input,enter again:\n";
   cin>>cash;
   }
  test=BankAccount(name,account,cash);
  test.Show();
  while (cin.get()!='\n');
  cout<<"Option: a)for saving.  b)for withdrawing  c)for showing    q)to quit\n";
  cout<<"Now enter your choice:";
  while(ch=cin.get(),ch!='q')
  {
    while (cin.get()!='\n');
    switch(ch)
     {
       case 'a':cout<<"Now enter money to save:";
                cin>>cash;
                while (!cin.good())
                {
                 cin.clear();
                 while (cin.get()!='\n');
                 cout<<"Invalid input,enter again:";
                 cin>>cash;
                }
                while (cin.get()!='\n');
                test.SaveMoney(cash);
                break;
       case 'b':cout<<"Now enter money to withdraw:";
                cin>>cash;
                while (!cin.good())
                {
                 cin.clear();
                 while (cin.get()!='\n');
                 cout<<"Invalid input,enter again:";
                 cin>>cash;
                }
                while (cin.get()!='\n');
                test.WithdrawMoney(cash);
                break;
      case 'c' :test.Show();
                break;
      default  :cout<<"Invalid input,Enter again:";
                continue;
     }
  cout<<"Now enter your choice:";
  }
  cout<<"Bye!"<<endl;
 return 0;
}  
