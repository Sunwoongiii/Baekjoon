#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n,m,k,t;
vector<pair<int,int>>v[5005];
vector<int>Friend;

vector<int>dijkstra(int a);
int findMid();

void reset(){
  for(int i = 0; i <= n; i++)v[i].clear();
  Friend.clear();
}

void sol(){
  cin>>t;
  while(t--){
    reset();
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
    cout<<findMid()<<'\n';
  }
}

vector<int> dijkstra(int a){
  vector<int> ans(n+1, 1e9);
  priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;

  pq.push({0,a});
  ans[a] = 0;

  while(!pq.empty()){
    int value = pq.top().first;
    int node = pq.top().second;
    pq.pop();

    if(value > ans[node])continue;

    for(int i = 0; i < v[node].size(); i++){
      int cost = v[node][i].first;
      int next = v[node][i].second;

      if(ans[next] > ans[node] + cost){
        ans[next] = ans[node] + cost;
        pq.push({ans[next], next});
      }
    }
  }
  return ans;
}

int findMid(){
  vector<int>totalDist(n+1, 0);

  for(int node : Friend){
    vector<int>dist = dijkstra(node);
    for(int i = 1; i <= n; i++){
      if(dist[i] != 1e9){
        totalDist[i] += dist[i];
      }
    }
  }

  int Min = 1e9;
  int ansNode = -1;

  for(int i = 1; i <= n; i++){
    if(totalDist[i] < Min || totalDist[i] == Min && ansNode > i){
      Min = totalDist[i];
      ansNode = i;
    }
  }
  return ansNode;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  sol();
}