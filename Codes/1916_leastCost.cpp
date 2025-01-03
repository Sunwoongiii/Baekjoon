#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <math.h>

using namespace std;

int n,m;
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
vector<pair<int,int>>v[1010];
int ans[1010] = {0};
int s,e;
bool visited[1010] = {false};

int bfs(){
  while(!pq.empty()){
    int value = pq.top().first;
    int node = pq.top().second;
    pq.pop();

    if(node == e){
      return ans[e];
    }

    if(visited[node]) continue;
    visited[node] = true;

    for(int i = 0; i < v[node].size(); i++){
      int next = v[node][i].first;
      int cost = v[node][i].second;

      if(visited[next]) continue;

      if(ans[next] <= ans[node] + cost) continue;

      ans[next] = ans[node] + cost;
      pq.push({ans[next], next});
    }
  }
  return 0;
}


int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin>>n>>m;
  for(int i = 0; i < m; i++){
    int a,b,c;
    cin>>a>>b>>c;
    v[a].push_back({b,c});
  }
  
  for(int i = 1; i <= n; i++){
    ans[i] = 2e9;
  }

  cin>>s>>e;
  ans[s] = 0;
  pq.push({0,s});
  cout<<bfs();
}