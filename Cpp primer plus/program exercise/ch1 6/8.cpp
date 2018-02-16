#include<iostream>
#include<set>
#include<vector>
#include<algorithm>
#include<string>
#include<cstdlib>
#include<ctime>
#include<iterator>

using std::string;
using std::cout;
using std::endl;
using std::set;
using std::vector;

const int MAXSIZE=10;
const int MINSIZE=5;

vector<string> namelist=
{"Saber","Lancer","Archer","Caster","Assassin","Rider","Bersker"};


void show(const string& str)
{
 cout<<str<<endl;
}

int main(void)
{
 srand(time(0));
 int ASIZE=rand()%(MAXSIZE-MINSIZE)+MINSIZE;
 set<string> MAT;
 set<string> PAT;

 for (int i=0;i<ASIZE;i++)
   MAT.insert( namelist[rand()%namelist.size()]);
 
 ASIZE=rand()%(MAXSIZE-MINSIZE)+MINSIZE;
 for (int i=0;i<ASIZE;i++)
   PAT.insert( namelist[rand()%namelist.size()]);
 
 cout<<"Before set_union:"<<endl;
 cout<<"MAT:"<<endl;  
 for_each(MAT.begin(),MAT.end(),show);
 cout<<endl<<"PAT:"<<endl;  
 for_each(PAT.begin(),PAT.end(),show);
 
 vector<string> union_f;
 std::insert_iterator<vector<string>> ins(union_f,union_f.begin());
 
 cout<<endl<<"After setting_union:"<<endl;
 set_union(MAT.begin(),MAT.end(),PAT.begin(),PAT.end(),ins);
 for_each(union_f.begin(),union_f.end(),show);
 
 return 0;
}
