#include <iostream>
#include <unordered_set>
using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int N,M,cnt=0;
  cin>>N>>M;

  unordered_set<string> us;
  for(int i = 0; i < N; i++){
    string str;
    cin>>str;
    us.insert(str);
  }

  for(int i = 0; i < M; i++){
    string str;
    cin>>str;
    if(us.find(str) != us.end())cnt++;
  }
  cout<<cnt;
}