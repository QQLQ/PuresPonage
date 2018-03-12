#include<iostream>
#include<fstream>
#include<cstdlib>

int main(int argc,char **argv)
{
  using std::cout;
  using std::cin;
  using std::endl;
  using std::ios;
  using std::exit;
  if (argc!=2)
  {
   cout<<"Usage:"<<argv[0]<<" [openfile name]"<<endl;
   exit(0);
  }
  std::ofstream opf(argv[1],ios::out|ios::app);
  if (!opf.is_open())
  {
   cout<<"Unable to open file properly,Program terminated."<<endl;
   exit(0);
  }
  int ch;
  ch=cin.get();
  while (ch!=EOF)
  {
   opf<<(char)ch;
   ch=cin.get();
  }
  opf.close();
 cout<<"Done!";
return 0;
}
