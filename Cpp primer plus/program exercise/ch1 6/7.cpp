#include<iostream>
#include<cstdlib>
#include<ctime>
#include<vector>
#include<algorithm>
#include<iterator>

const int TOTAL=51;
const int PICKED=6;

using std::endl;
using std::cout;
using std::vector;
using std::cin;


vector<int> Lotto(int total=TOTAL,int picked=PICKED);

int main(void)
{
 vector<int> winner(Lotto(TOTAL,PICKED));
 sort(winner.begin(),winner.end());
 copy(winner.begin(),winner.end(), std::ostream_iterator<int,char>(cout," "));
  
return 0;
}

vector<int> Lotto(int total,int picked)
{
 std::srand(std::time(0));
 vector<int> pool(total);
 for (int i=0;i<total;i++)
  pool[i]=i+1;
 std::random_shuffle(pool.begin(),pool.end());
 vector<int> winner(picked);
 for (int i=0;i<picked;i++)
  winner[i]=pool[i];
 return winner;
}
