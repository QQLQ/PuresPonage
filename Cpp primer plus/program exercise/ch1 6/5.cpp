#include<iostream>
#include<algorithm>
#include<cstdlib>
#include<ctime>
#include<string>
#include<fstream>
#include<vector>
const int ARSIZE=35;
const long MaxTestNumber=20; 

template<typename T>
int reduce(T ar[],int n);
template<typename T>
void show(T ar[],int n);

int main(void)
{
 using std::srand;
 using std::rand;
 using std::endl;
 using std::cout;
 using std::vector;
 using std::string;
 
 std::ifstream Word_file;
 Word_file.open("wordlist");
 if (!Word_file.is_open())
 {
  cout<<"Faild to open file,program terminate."<<endl;
  exit(1);
 }
 vector<string> tar;
 string temp;
 while(Word_file>>temp)
   tar.push_back(temp);
 int word_list_size=tar.size();
 string wordlist[word_list_size];
 copy(tar.begin(),tar.end(),wordlist);
 
 int size=ARSIZE; 
 long ar[ARSIZE];
 srand(time(0));
 int i;
 cout<<"long instance**"<<endl;
 for (i=0;i<ARSIZE;i++)
   ar[i]=rand()%(MaxTestNumber+1);
 cout<<"Before reduced:"<<endl;
 show(ar,ARSIZE);
 cout<<"the size is "<<size<<endl;

 size=reduce(ar,ARSIZE);
 cout<<endl<<"After reduced:"<<endl;
 show(ar,size);
 cout<<"the size is "<<size<<endl;
 cout<<endl<<endl<<"string instance**"<<endl;
 cout<<"Before sorted:"<<endl;
 show(wordlist,word_list_size);
 cout<<"The size is currently "<<word_list_size<<endl;
 size=reduce(wordlist,word_list_size);
 cout<<endl<<endl<<"After sorted:"<<endl;
 show(wordlist,size);
 cout<<"The size is currently "<<size<<endl;
  
return 0;
}
 
template<typename T>
int reduce(T ar[],int n)
{
  std::sort(&ar[0],&ar[n]);
  T* pt= std::unique(&ar[0],&ar[n]);
  return (pt-&ar[0]);
}

template<typename T>
void show(T ar[],int n)
{
  using std::endl;
  using std::cout;
 int i;
 for (i=0;i<n;i++)
 { 
  cout<<ar[i]<<" ";
  if ((i+1)%5==0)
   cout<<endl;
 }
 if (i%5!=0)
   cout<<endl;
}
