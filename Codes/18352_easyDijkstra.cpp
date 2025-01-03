#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n,m,k,x;
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
vector<int>adj[300003];
int dist[300003];
vector<int>dap;

void dijkstra(){
  pq.push({0,x});
  dist[x] = 0;

  while(!pq.empty()){
    int currentDist = pq.top().first;
    int node = pq.top().second;
    pq.pop();

    if(currentDist > dist[node]) continue;

    for(int next : adj[node]){
      int nextDist = currentDist + 1;
      if(nextDist < dist[next]){
        dist[next] = nextDist;
        pq.push({nextDist, next});
      }
    }
  }
}

int main(){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  cin>>n>>m>>k>>x;

  for(int i = 0; i < m; i++){
    int a,b;
    cin>>a>>b;
    adj[a].push_back(b);
  }
  fill(dist, dist+n+1, 2e9);
  dijkstra();
  for(int i = 1; i <= n; i++){
    if(dist[i] == k){
      dap.push_back(i);
    }
  }
  if(dap.empty()) cout<<"-1";
  else{
    sort(dap.begin(), dap.end());
    for(int city : dap){
      cout<<city<<"\n";
    }
  }
  return 0;
}