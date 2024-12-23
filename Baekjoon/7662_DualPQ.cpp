#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

int T,K;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin>>T;
  while(T--){
    cin>>K;
    multiset<int>ms;
    for(int i = 0; i < K; i++){
      char cmd;
      int input;

      cin>>cmd>>input;

      if(cmd == 'I')ms.insert(input);
      else if(cmd == 'D'){
        if(ms.size() == 0)continue;
        else if(input == -1)ms.erase(ms.begin());
        else if(input == 1)ms.erase(prev(ms.end()));
      }
    }

    if(ms.empty())cout<<"EMPTY\n";
    else cout<<*ms.rbegin()<<' '<<*ms.begin()<<'\n';
  }
  return 0;
}