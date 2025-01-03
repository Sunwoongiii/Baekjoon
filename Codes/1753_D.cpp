#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <math.h>

using namespace std;
bool visited[20200];
int dist;
int n,m;
int num;
vector<pair<int,int>>v[300300];
int ans[20200];
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;

void dijkstra(){
  while(!pq.empty()){
    int value = pq.top().first;
    int node = pq.top().second;
    pq.pop();

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
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin>>n>>m>>num;
  for(int i = 0; i < m; i++){
    int a,b,c;
    cin>>a>>b>>c;
    v[a].push_back({b,c});
  }

  for(int i = 1; i <= n; i++){
    ans[i] = 2e9;
    visited[i] = false;
  }
  
  ans[num] = 0;
  pq.push({0,num});
  dijkstra();

  for(int i = 1; i <= n; i++){
    if(ans[i] == 2e9) cout<<"INF\n";
    else cout<<ans[i]<<"\n";
  }
}