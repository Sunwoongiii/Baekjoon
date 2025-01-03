#include <iostream>
#include <queue>

using namespace std;
using ll = long long;

int bfs(ll a, ll b){
  queue<pair<ll,ll>>q;
  q.push({a,1});
  
  while(!q.empty()){
    ll node = q.front().first;
    ll value = q.front().second;
    q.pop();

    if(a > b) return -1;
    if(node == b) return value;
    if(node * 2 <= b) q.push({node*2, value+1});
    if(node * 10 + 1 <= b) q.push({node*10 +1, value+1});
  }
  return -1;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  ll a,b;
  cin>>a>>b;
  cout<<bfs(a,b);
}