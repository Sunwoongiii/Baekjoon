#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <math.h>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <sstream>

using namespace std;
using ll = long long;

int n,m,s,e,nodeSum = 0;
int ans[1001];
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
bool visited[1001];
vector<pair<int,int>>v[100001];
vector<pair<int,int>> tlqkf;

int dijkstra(){
  tlqkf.push_back({s,s});
  pq.push({0,s});
  while(!pq.empty()){
    int value = pq.top().first;
    int node = pq.top().second;
    pq.pop();
    nodeSum++;

    if(visited[node]) continue;
    if(node == e) return ans[node];
    visited[node] = true;

    for(int i = 0; i < v[node].size(); i++){
      int cost = v[node][i].first;
      int next = v[node][i].second;

      if(visited[next]) continue;
      if(ans[next] > ans[node] + cost){
        ans[next] = ans[node] + cost;
        tlqkf.push_back({node, next});
        pq.push({ans[next], next});
      }
    }
  }
  return -1;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin>>n>>m;
  for(int i = 0; i < m; i++){
    int a,b,c;
    cin>>a>>b>>c;
    v[a].push_back({c,b});
  }
  fill(ans, ans+n+1, 2e9);
  fill(visited, visited+n+1, false);
  cin>>s>>e;
  ans[s] = 0;
  int result = dijkstra();
  cout<<result<<"\n";
  
  for(int i = 0; i < tlqkf.size(); i++){
    cout<<tlqkf[i].first<<" "<<tlqkf[i].second<<"\n";
  }
}