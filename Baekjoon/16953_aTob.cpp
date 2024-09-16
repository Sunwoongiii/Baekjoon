#include <iostream>
#include <vector>
#include <queue>
#define inf 1000000000+1
using namespace std;
using ll = long long;

ll a,b;
ll visited[inf];
priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>>pq;
ll ans[inf];

ll dijkstra(){
  pq.push({1, a});

  while(!pq.empty()){
    ll value = pq.top().first;
    ll node = pq.top().second;
    pq.pop();

    if(visited[node]) continue;
    visited[node] = true;

    if(node == b) return ans[node];

    if(node - 1 > 0 && !visited[node]){
      pq.push({value+1, node-1});
      visited[node-1] = true;
    }

    if(node * 2 < inf && !visited[node]){
      pq.push({value+1, node*2});
      visited[node*2] = true;
    }
  }
  return -1;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin>>a>>b;
  cout<<dijkstra();
}