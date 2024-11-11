#include <iostream>
#include <queue>
using namespace std;

int n,types, cnt[10],ans;
queue<int>q;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin>>n;
  while(n--){
    int fruit;
    cin>>fruit;

    q.push(fruit);
    if(cnt[fruit]++ == 0){
      ++types;
    }
    while(types > 2){
      fruit = q.front();
      q.pop();

      if(--cnt[fruit] == 0){
        --types;
      }
    }
    ans = max(ans, static_cast<int>(q.size()));
  }
  cout<<ans;
}