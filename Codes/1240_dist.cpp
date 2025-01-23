#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N,M;
vector<pair<int,int>>v[1010];

int dijkstra(int start, int end){
  priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
  int ans[1010];
  fill(ans,ans+N+1,1e9);
  ans[start] = 0;
  pq.push({0,start});

  while(!pq.empty()){
    int node = pq.top().second;
    int value = pq.top().first;
    pq.pop();

    if(ans[node] > value) continue;
    for(int i = 0; i < v[node].size(); i++){
      int cost = v[node][i].first;
      int next = v[node][i].second;

      if(ans[next] > cost + value){
        ans[next] = cost + value;
        pq.push({ans[next], next});
      }
    }
  }
  return ans[end] != 1e9 ? ans[end] : -1;
}

void sol(){
  cin>>N>>M;
  for(int i = 0; i < N-1; i++){
    int a,b,c;
    cin>>a>>b>>c;
    v[a].push_back({c,b});
    v[b].push_back({c,a});
  }

  while(M--){
    int s,e;
    cin>>s>>e;

    cout<<dijkstra(s,e)<<'\n';
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  sol();
}