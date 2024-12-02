#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <tuple>
using namespace std;

int N,K,H;
priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>,greater<tuple<int,int,int>>>pq;
vector<pair<int,int>>v[200200];
int ans[200200];

void getInput(){
  cin>>N>>K>>H;
  for(int i =0; i < K; K++){
    int a,b,c;
    v[a].push_back({c,b});
    v[b].push_back({c,a});
  }
}

int dijkstra(int start){
  fill(ans, ans+N+1, 1e9);
  pq.push({0,start});
  ans[start] = 0;

  while(!pq.empty()){
    int value, node, HP;
    tie(value, node, HP) = pq.top();
    pq.pop();

    if(HP == 0)return value;

    for(int i = 0; i < v[node].size(); i++){
      int cost = v[node][i].first;
      int next = v[node][i].second;

      if(ans[next] > ans[node] + cost){
        ans[next] = ans[node] + cost;
        pq.push({ans[next], next, HP--})
      }
    }
  }
  return -1;
}