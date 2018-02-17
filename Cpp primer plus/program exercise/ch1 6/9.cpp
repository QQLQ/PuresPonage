#include<iostream>
#include<vector>
#include<list>
#include<cstdlib>
#include<algorithm>
#include<ctime>

const int MAXSIZE=5000000;
const int BIGGEST_NUM=1000000;

int main(void)
{
  using std::cout;
  using std::endl;
  using std::srand;
  using std::rand;
  using std::vector;
  using std::list;
  using std::sort;
  
  cout<<"Initializing vector<int> vi0>>>>>";
  srand(time(0));
  vector<int> vi0;
  for (int i=0;i<MAXSIZE;i++)
    vi0.push_back(rand()%BIGGEST_NUM);
  vector<int> vi(vi0);
  list<int> li(vi0.begin(),vi0.end());
  cout<<"Done!"<<endl;

  
  clock_t start=clock();
  clock_t end;
  
  cout<<"Now sorting vector (with STL sort)>>>>";
  sort(vi.begin(),vi.end());
  end=clock();
  cout<<"Done!"<<(double)(end-start)/CLOCKS_PER_SEC<<" seconds spent in total."<<endl;
  
  start=clock();
  cout<<"Now sorting list (with STL sort)>>>>";
  li.sort();
  end=clock();
  cout<<"Done!"<<(double)(end-start)/CLOCKS_PER_SEC<<" seconds spent in total."<<endl;
    
  return 0;
}
