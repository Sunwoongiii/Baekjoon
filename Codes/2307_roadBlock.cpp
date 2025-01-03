#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int ans[1010];
int N,M;
vector<pair<int,int>>v[5050];
vector<int>path;

void getInput(){
  cin>>N>>M;
  for(int i = 0; i < M; i++){
    int a,b,c;
    cin>>a>>b>>c;
    v[a].push_back({c,b});
    v[b].push_back({c,a});
  }
}

int initialDijkstra(){
  int parent[1010];
  fill(parent, parent + N + 1, -1);
  fill(ans, ans+N+1, 1e9); 
  ans[1] = 0;
  priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
  pq.push({0,1});

  while(!pq.empty()){
    int node = pq.top().second;
    int value = pq.top().first;
    pq.pop();

    if(ans[node] < value)continue;

    for(int i = 0; i < v[node].size(); i++){
      int next = v[node][i].second;
      int cost = v[node][i].first;

      if(ans[next] > value + cost){
        ans[next] = value + cost;
        parent[next] = node;
        pq.push({ans[next], next});
      }
    }
  }
  for(int i = N; i != -1; i = parent[i]){
    path.push_back(i);
  }
  reverse(path.begin(),path.end());
  return ans[N] == 1e9 ? -1 : ans[N];
}

int dijkstra(int a, int b){
  fill(ans, ans+N+1, 1e9);
  ans[1] = 0;
  priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
  pq.push({0,1});

  while(!pq.empty()){
    int value = pq.top().first;
    int node = pq.top().second;
    pq.pop();

    for(int i = 0 ; i < v[node].size(); i++){
      int cost = v[node][i].first;
      int next = v[node][i].second;

      if((a == node && b == next) || (a == next && b == node))continue;
      if(ans[next] > value + cost){
        ans[next] = value + cost;
        pq.push({ans[next], next});
      }
    }
  }
  return ans[N] == 1e9 ? -1 : ans[N];
}

void sol(){
  getInput();
  int initialCost = initialDijkstra();
  if(initialCost == -1){
    cout<<-1;
    return;
  }

  int dap = dijkstra(path[0], path[1]);
  if(dap == -1){cout<<-1; return;}
  dap -= initialCost;
  for(int i = 1; i < path.size()-1; i++){
    int to = path[i];
    int go = path[i+1];

    int blockedCost = dijkstra(to,go);
    if(blockedCost == -1){cout<<-1; return;}
    blockedCost-=initialCost;

    dap = max(dap, blockedCost);
  }
  cout<<dap;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  sol();
  return 0;
}