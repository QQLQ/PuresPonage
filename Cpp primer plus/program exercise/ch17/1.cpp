#include<iostream>

int main(void)
{
 using std::cout;
 using std::cin;
 using std::endl;
 
 cout<<"enter the sentence:"<<endl;
 char ch;
 int count=0;
 cin.get(ch);
 while (1)
 { 
  count++;
  cin.get(ch);
  if (cin.peek()=='$')
    break;
 }
 
 cout<<count<<" chars before \'$\'"<<endl;
 cout<<"And the followoing are(if there is):"<<endl;
 char sent[255];
 cin.getline(sent,255);
 cout<<sent<<endl<<"Done!"<<endl;
 return 0;
}
