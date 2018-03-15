#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>

using namespace std;

class Store
{
 private:
  size_t len_m; 
  string str_m; 
  ofstream& os_m;
 public:
  Store(ofstream&os);
  void operator() (const string& str);
  ~Store(){}
};

void ShowStr(const string& str)
{
  cout<<str<<endl;
}
void GetStrs(istream& is,vector<string>& ves)
{
 size_t len;
 while ( is.read((char*)&len,sizeof(size_t)) )
  {
   char *cstr=new char[len+1];
   is.read((char*)cstr,len);
   cstr[len]='\0';
   ves.push_back(string(cstr));
   delete cstr;
  }
}


int main()
{
  using namespace std;
  vector<string> vostr;
  string temp;
  
  cout<<"Enter string(emptyline to quit):\n ";
  while (getline(cin,temp)&&temp[0]!='\0')
     vostr.push_back(temp);
  cout<<"Here is your input.\n";
  for_each(vostr.begin(),vostr.end(),ShowStr);
  
  ofstream fout("strings.dat",ios_base::out|ios_base::binary);
  for_each(vostr.begin(),vostr.end(),Store(fout));
  fout.close();
    
  vector<string> vistr;
  ifstream fin("strings.dat",ios_base::in|ios_base::binary);
  if(!(fin.is_open()))
  {
    cerr<<"Could not open file for input.\n";
    exit(EXIT_FAILURE);
  }
  GetStrs(fin,vistr);
  cout<<"\nHere are the strings read from the file:\n";
  for_each(vistr.begin(),vistr.end(),ShowStr);
  
  return 0;
}

Store::Store(ofstream&os):os_m(os){};
void Store::operator() (const string& str)
{
 len_m=str.length();
 os_m.write((char*)&len_m,sizeof(size_t));
 os_m.write(str.data(),len_m);
}
