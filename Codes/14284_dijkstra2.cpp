#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <math.h>
#include <functional>

using namespace std;

int n,m,s,t;
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
vector<pair<int,int>>v[100100]; //value, node
bool visited[100100] = {false};
int ans[100100] = {0};

int dijkstra(){
  while(!pq.empty()){
    int value = pq.top().first;
    int node = pq.top().second;
    pq.pop();

    if(node == t){
      cout<<ans[t];
      return 0;
    }

    if(visited[node]) continue;
    visited[node] = true;

    for(int i = 0; i < v[node].size(); i++){
      int next = v[node][i].first;
      int cost = v[node][i].second;

      if(visited[next]) continue;
      if(ans[next] > ans[node] + cost){
        ans[next] = ans[node] + cost;
        pq.push({ans[next], next});
      }
    }
  }
  return -1;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin>>n>>m;
  for(int i = 1; i <= m; i++){
    int a,b,c;
    cin>>a>>b>>c;
    v[a].push_back({b,c});
    v[b].push_back({a,c});
  }
  for(int i = 1; i <= n; i++){
    ans[i] = 2e9;
  }
  cin>>s>>t;
  ans[s] = 0;
  pq.push({0, s});
  dijkstra();
  return 0;
}