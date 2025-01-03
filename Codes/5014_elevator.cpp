#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int f,s,g,u,d;
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
bool visited[1000001];
int ans[1000001];

int dijkstra(){
  pq.push({0, s});

  while(!pq.empty()){
    int value = pq.top().first;
    int node = pq.top().second;
    visited[node] = true;
    pq.pop();

    if(node == g) return value;

    if(node + u <= f && !visited[node+u]){
      visited[node+u] = true;
      pq.push({value+1, node+u});
    }

    if(node - d > 0 && !visited[node-d]){
      visited[node-d] = true;
      pq.push({value+1, node-d});
    }
  }
  return -1;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin>>f>>s>>g>>u>>d;
  int ans = dijkstra();
  if(ans == -1) cout<<"use the stairs";
  else cout<<ans;

  return 0;
}