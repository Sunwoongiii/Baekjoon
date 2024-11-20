#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n,m,k,t;
bool visited[110];
int ans[110];
vector<pair<int,int>>v[5005];
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
vector<int>Friend;

void reset(){
  fill(ans, ans+n+1, 1e9);
  fill(visited, visited + n +1, false);
  while(!pq.empty())pq.pop();
  for(int i = 0; i <= m; i++) v[i].clear();
  Friend.clear();
}

void sol(){
  cin>>t;
  while(t--){
    cin>>n>>m;
    for(int i = 0; i < m; i++){
      int a,b,c;
      cin>>a>>b>>c;
      v[a].push_back({c,b});
      v[b].push_back({c,a});
    }
    cin>>k;
    for(int i = 0; i < k; i++){
      int a;
      cin>>a;
      Friend.push_back(a); 
    }

  }
}

void dijkstra(int a){
  reset();
  pq.push({0,a});
  visited[a] = true;

  while(!pq.empty()){
    int value = pq.top().first;
    int node = pq.top().second;
    pq.pop();

    for(int i = 0; i < v[node].size(); i++){
      int cost = v[node][i].first;
      int next = v[node][i].second;

      if(!visited[next] && ans[next] > ans[node] + cost){
        ans[next] = ans[node] + cost;
        visited[next] = true;
      }
    }
  }
}

void findMid(){
  for(int node : Friend){
    
  }
}