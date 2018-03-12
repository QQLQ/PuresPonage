#include<iostream>
#include<fstream>
#include<cstdlib>

int main(int argc,char* *argv)
{
  using std::cout;
  using std::endl;
  
  if (argc!=3)
  {
   std::cerr<<"Usage:"<<argv[0]<<" [src file] [tar file]"<<endl;
   exit(0);
  }
  std::ifstream fin(argv[1]);
  std::ofstream fout(argv[2],std::ios::out|std::ios::app);
  if (!(fin.is_open()&&fout.is_open()) )
  {
   std::cerr<<"Unable to openfile.Please retry."<<endl;
   std::exit(1);
  }
  char ch;
  while (fin.get(ch))
   fout<<ch;
  fin.close();
  fout.close();
  cout<<"Done"<<endl;
  return 0;
}
