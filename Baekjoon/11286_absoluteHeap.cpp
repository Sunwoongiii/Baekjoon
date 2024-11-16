#include <iostream>
#include <set>
#include <cmath>
using namespace std;

int N;
multiset<pair<int,int>>ms;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin>>N;
  while(N--){
    int x;
    cin>>x;

    if(x == 0){
      if(ms.empty())cout<<0<<'\n';
      else{
        auto it = ms.begin();
        cout<<it->second<<'\n';
        ms.erase(it);
      }
    }

    else{
      ms.insert({abs(x),x});
    }
  }
  return 0;
}