#include<iostream>
#include<algorithm>
#include<cstdlib>
#include<cstring>

using namespace std;

bool palindrome1(const string& str);
bool NonLower(const string& str);

int main(void)
{
  const char* Test[5]={"tot","tssppsst","tab","test","Job"};
  for (int i=0;i<5;i++)
    {
     if (palindrome1(Test[i]) )
      cout<<Test[i]<<" is palindromed!"<<endl;
     else
      cout<<Test[i]<<" is not palindromed!"<<endl;
    }
  
     
return 0;
}

bool NonLower(const string& str)
{
  char LowerAr[26];
  for(int i=0;i<26;i++)
    LowerAr[i]='a'+i;
  if (str.size()==0)
    return true;
  return string::npos!=str.find_first_not_of(LowerAr);
}

   
bool palindrome1(const string& str)
{
 if(NonLower(str))
 {
  cout<<str<<" is not leagal."<<endl;
  cout<<"Fully_lowered_characters_only word please!"<<endl;
  exit(1);
 } 

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
