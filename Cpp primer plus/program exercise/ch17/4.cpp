#include<iostream>
#include<fstream>
#include<cstdlib>
#include<string>

int main(int argc,char** argv)
{
  using std::cerr;
  using std::cout;
  using std::endl;
  using std::exit;  
  using std::string;
  
  if (argc!=3)
  {
    cerr<<"Usage:"<<argv[0]<<" [file_1] [file_2]"<<endl;
    exit(0);
  }
  
  std::ifstream file_1(argv[1]);
  std::ifstream file_2(argv[2]);
  std::ofstream tout("tar");
  
  if(!file_1.is_open()||!file_2.is_open()||!tout.is_open())
  {
   cerr<<"Unable to open file.Program terminated."<<endl;
   exit(0);
  }
  
  string str_1;
  string str_2;
  getline(file_1,str_1);
  getline(file_2,str_2);
  while (file_1&&file_2)
  {
   tout<<str_1<<" "<<str_2<<endl;
   getline(file_1,str_1);
   getline(file_2,str_2);
  }
  if (file_1)
   while (file_1)
   {
   tout<<str_1<<endl;
   getline(file_1,str_1);
   }
  if (file_2)
   while (file_2)
   {
   tout<<str_2<<endl;
   getline(file_2,str_2);
   }
   file_1.close();
   file_2.close();
   cout<<"Done!"<<endl;
   
return 0;
}
