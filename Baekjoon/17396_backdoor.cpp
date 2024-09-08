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
int seen[100100];
priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long, int>>>pq;
vector<pair<int,int>>v[100100]; // value, node 순서
bool visited[100100];
long long ans[100100];

long long dijkstra(){
  while(!pq.empty()){
    long long value = pq.top().first;
    int node = pq.top().second;
    pq.pop();

    if(node == n-1){
      return ans[n-1];
    }

    if(visited[node] || seen[node]) continue;
    visited[node] = true;

    for(int i = 0; i < v[node].size(); i++){
      int next = v[node][i].first;
      int cost = v[node][i].second;

      if(visited[next] || seen[next]) continue;
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
  for(int i = 0; i < n; i++){
    cin>>seen[i];
  }
  seen[n-1] = 0;
  for(int i = 0; i < m; i++){
    int a,b,c;
    cin>>a>>b>>c;
    v[a].push_back({b,c});
    v[b].push_back({a,c});
  }
  for(int i = 0; i < n; i++){
    ans[i] = 2e18;
  }
  ans[0] = 0;
  pq.push({0,0});
  cout<<dijkstra();
  return 0;
}