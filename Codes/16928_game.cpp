#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>
using namespace std;

int n,m;
vector<pair<int,int>>v[101];
int ans[101];
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;

void getInput(){
  cin>>n>>m;
  int a,b;
  for(int i = 0; i < n+m; i++){
    cin>>a>>b;
    v[a].push_back({0,b});
  }
  fill(ans, ans+101, INT_MAX);
}

int dijkstra(){
  pq.push({0,1});
  ans[1] = 0;

  while(!pq.empty()){
    int value = pq.top().first;
    int node = pq.top().second;
    pq.pop();

    if(ans[node] < value)continue;
    if(node == 100) return value;

    if(v[node].empty()){
      for(int i = 1; i <= 6; i++){
        int cost = 1;
        int next = node + i;
        if(next > 100)continue;

        if(ans[next] > cost + ans[node]){
          ans[next] = cost + ans[node];
          pq.push({ans[next], next});
        }
      }
    }

    else{
      for(int i = 0; i < v[node].size(); i++){
        int cost = v[node][i].first;
        int next = v[node][i].second;

        if(ans[next] > cost + ans[node]){
          ans[next] = cost + ans[node];
          pq.push({ans[next], next});
        }
      }
    }
  }
  return -1;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  getInput();
  cout<<dijkstra();
}