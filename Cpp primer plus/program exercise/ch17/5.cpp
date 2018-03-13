#include<iostream>
#include<fstream>
#include<set>
#include<string>
#include<cstdlib>
#include<algorithm>

int main(void)
{
 using std::ifstream;
 using std::ofstream;
 using std::cout;
 using std::cerr;
 using std::endl;
 using std::string;
 using std::set;
 
 ifstream fin_1("a");
 ifstream fin_2("b");
 ofstream fout("matnpat.dat");
 
 if(!(fin_1.is_open()&&fin_2.is_open()) )
 {
  cerr<<"Unable to open file."<<endl;
  exit(0);
 }
 
 set<string> Mat,Pat,union_PaM;
 string name;
 while (fin_1>>name)
  Mat.insert(name);
 while (fin_2>>name)
  Pat.insert(name);
 std::insert_iterator<set<string> >ins(union_PaM,union_PaM.begin());
 std::set_union(Mat.begin(),Mat.end(),Pat.begin(),Pat.end(),ins);
 set<string>::iterator iter; 
 for(iter=union_PaM.begin();iter!=union_PaM.end();iter++)
   fout<<*iter<<" ";
 return 0;
}
