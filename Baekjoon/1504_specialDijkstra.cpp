#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define INF 2e9


using namespace std;

int n,e,v1,v2;
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
vector<pair<int,int>>v[200002];
bool visited[808];
int ans[200002];

int dijkstra(int start, int end){
  fill(ans, ans+n+1, 2e9);
  fill(visited, visited+n+1, false);
  pq.push({0, start});
  ans[start] = 0;

  while(!pq.empty()){
    int value = pq.top().first;
    int node = pq.top().second;
    pq.pop();

    if(visited[node]) continue;
    visited[node];

    if(node == end) return ans[node];

    for(int i = 0; i <v[node].size(); i++){
      int cost = v[node][i].first;
      int next = v[node][i].second;

      if(visited[next]) continue;
      if(ans[next] > ans[node] + cost){
        ans[next] = ans[node] + cost;
        pq.push({ans[next], next});
      }
    }
  }
  return INF;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin>>n>>e;
  for(int i = 0; i < e; i++){
    int a,b,c;
    cin>>a>>b>>c;
    v[a].push_back({c,b});
    v[b].push_back({c,a});
  }
  cin>>v1>>v2;

  int s_to_v12 = min(dijkstra(1,v1), dijkstra(1, v2));
  int v1_to_v2 = dijkstra(v1, v2);
  int v12_to_e = min(dijkstra(v1, e), dijkstra(v2, e));

  if(s_to_v12 == INF || v1_to_v2 == INF || v12_to_e == INF){
    cout<<-1;
    return 0;
  }
  else cout<<s_to_v12+v1_to_v2+v12_to_e;
}