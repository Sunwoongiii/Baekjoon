#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <math.h>
#include <tuple>
//씨발런타임에러좆같노
using namespace std;
int n,e,s,u;
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
vector<pair<int,int>>v[200002];//value, node 순서
bool visited[808];
int ans[808];

void reset(){
  for(int i = 1; i <= e; i++){
    ans[i] = 2e9;
    visited[i] = false;
  }
  while(!pq.empty()) pq.pop();
}

int dijkstra(int start, int end){
  reset();
  ans[start] = 0;
  pq.push({0,start});

  while(!pq.empty()){
    int value = pq.top().first;
    int node = pq.top().second;
    pq.pop();

    if(node == end) return ans[end];

    if(visited[node]) continue;
    visited[node] = true;

    for(int i = 0; i < v[node].size(); i++){
      int cost = v[node][i].first;
      int next = v[node][i].second;

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

  cin>>n>>e;
  for(int i = 1; i <= e; i++){
    int a,b,c;
    cin>>a>>b>>c;
    v[a].push_back({c,b});
    v[b].push_back({c,a});
  }
  cin>>s>>u;

  int start_to_s = dijkstra(1, s);
  int s_to_u = dijkstra(s,u);
  int u_to_n = dijkstra(u, n);

  if(start_to_s == -1 || s_to_u == -1 || u_to_n == -1){
    cout<<-1;
    return 0;
  }else{
    cout<<start_to_s + s_to_u + u_to_n;
    return 0;
  }
}