#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
const int INF = 2e9;

int n,m,s,e,nodeSum = 0;
int ans[1001];
vector<pair<int,int>>v[1001];
vector<int>previous;
int route[1001];//직전 노드 기록용
bool visited[1001];
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;

int dijkstra(){
  fill(ans, ans+n+1, INF);
  fill(visited, visited+n+1, false);
  fill(route, route + n+1, -1);
  pq.push({0,s});
  ans[s] = 0;

  while(!pq.empty()){
    int value = pq.top().first;
    int node = pq.top().second;
    pq.pop();

    if(visited[node]) continue;
    visited[node] = true;
    
    if(node == e) return ans[node];

    for(int i = 0; i <v[node].size(); i++){
      int cost = v[node][i].first;
      int next = v[node][i].second;

      if(ans[next] > ans[node] + cost){
        ans[next] = ans[node] + cost;
        pq.push({ans[next], next});
        route[next] = node;
      }
    }
  }
  return -1;
}

void checkPath(int node){
  if(node == s){
    previous.push_back(s);
    return;
  }
  checkPath(route[node]);
  previous.push_back(node);
  nodeSum++;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin>>n>>m;
  for(int i = 0; i < m; i++){
    int a,b,c;
    cin>>a>>b>>c;
    v[a].push_back({c,b});
  }
  cin>>s>>e;
  int result = dijkstra();
  checkPath(e);
  cout<<result<<"\n";
  cout<<previous.size()<<"\n";
  for(int i = 0; i < previous.size(); i++){
    cout<<previous[i]<<" ";
  }
}