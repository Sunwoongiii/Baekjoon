#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N,M,K;
vector<pair<int,int>>v[50050];
vector<pair<int,int>>path;

void getInput(){
  cin>>N>>M>>K;
  for(int i = 0; i < M; i++){
    int a,b,c;
    cin>>a>>b>>c;
    v[a].push_back({c,b});
    v[b].push_back({c,a});
  }
}

int initialDijkstra(){
  int ans[N+1];
  int parent[N+1];
  fill(ans, ans+N+1, 1e9);
  fill(parent, parent + N + 1, -1);

  ans[1] = 0;
  priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
  pq.push({0,1});

  while(!pq.empty()){
    int value = pq.top().first;
    int node = pq.top().second;
    pq.pop();

    if(ans[node] < value)continue;

    for(int i = 0; i < v[node].size(); i++){
      int cost = v[node][i].first;
      int next = v[node][i].second;

      if(ans[next] > cost + value){
        ans[next] = cost + value;
        parent[next] = node;
        pq.push({ans[next], next});
      }
    }
  }

  for(int node = N; node != -1; node = parent[node]){
    if(parent[node] != -1){
      int weight = ans[node] - ans[parent[node]];
      path.push_back({weight, node});
    }
  }
  reverse(path.begin(), path.end());
  return ans[N];
}

void sol(){
  getInput();
  int roadCnt = path.size();
  int initial = initialDijkstra();

  if(roadCnt <= K){
    cout<<initial<<'\n';
    return;
  }
  else{
    sort(path.begin(), path.end(), [](const pair<int,int>&a, const pair<int,int>&b){return a.first > b.first;});
    int reduced = 0;
    for(int i = 0; i < K; i++){
      reduced += path[i].first;
    }
    cout<<reduced<<'\n';
    return;
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  sol();
  for(int i = 0; i < path.size(); i++){
    cout<<path[i].first<<' '<<path[i].second<<'\n';
  }
}