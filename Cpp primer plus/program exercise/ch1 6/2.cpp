#include<iostream>
#include<cctype>
#include<string>
using namespace std;

string conv(const string& str);
bool palindrome1(const string& str);

int main(void)
{
  const char* Test[5]={"tot","tssppsst","tab","test","Madam,I'm Adam"};
  cout<<conv("Madam,I'm Adam")<<endl;
  for (int i=0;i<5;i++)
    {
     if (palindrome1(Test[i]) )
      cout<<Test[i]<<" is palindromed!"<<endl;
     else
      cout<<Test[i]<<" is not palindromed!"<<endl;
    }
  
     
return 0;
}

string conv(const string& str)
{
  string tar;
  const char*pt=&str[0];
  for (int i=0,size=str.size();i<size;i++,pt++)
  {
   if (isalnum(*pt))
     tar+=tolower(*pt);
  }      
  return tar;
}
  
bool palindrome1(const string& sam)
{
  string str=conv(sam);
  const char*pt=&str[0];
  const char*pe=&str[str.size()-1];
  bool palin=true;
  
  while (pe-pt>0)
  {
   if(*pt!=*pe)
    {
     palin=false;
     break;
    }
   pt++;
   pe--;
  }
  return palin;
}
