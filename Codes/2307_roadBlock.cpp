#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int N,M;
vector<pair<int,int>>v[5050];
int ans[1010];
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;

void getInput(){
  cin>>N>>M;
  for(int i = 0; i < M; i++){
    int a,b,c;
    cin>>a>>b>>c;
    v[a].push_back({c,b});
    v[b].push_back({c,a});
  }
}

int dijkstra(){
  fill(ans, ans+N+1, 1e9);
  ans[1] = 0;
  pq.push({0,1});
  
  while(!pq.empty()){
    int node = pq.top().first;
    int value = pq.top().second;

    if(value > ans[node])continue;
    for(int i = 0; i < v[node].size(); i++){
      int cost = v[node][i].first;
      int next = v[node][i].second;

      if(ans[next] > value  + cost){
        ans[next] = value + cost;
        pq.push({ans[next], next});
      }
    }
  }
  return ans[N] == 1e9 ? -1 : ans[N];
}

void sol(){
  getInput();
  
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);


}