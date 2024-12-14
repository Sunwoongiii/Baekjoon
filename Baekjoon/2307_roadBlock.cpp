#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <tuple>
using namespace std;

int N,M;
vector<tuple<int,int,int>>v[5050];
int ans[1010];

void getInput(){
  cin>>N>>M;
  for(int i =0; i < M; i++){
    int a,b,c;
    cin>>a>>b>>c;
    v[a].push_back({c,b,i});
    v[b].push_back({c,a,2*M-i-1});
  }
}

int dijkstra(int a){
  priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
  fill(ans, ans+N+1, 1e9);
  pq.push({0,1});
  ans[1] = 0;

  while(!pq.empty()){
    int value = pq.top().first;
    int node = pq.top().second;
    pq.pop();
    
    // if(node == N)return value;

    for(int i = 0; i < v[node].size(); i++){
      int index, cost, next;
      tie(cost,next,index) = v[node][i];
      if(index == a || index + a == 2*M-1)continue;

      if(ans[next] > ans[node] + cost){
        ans[next] = ans[node] + cost;
        pq.push({ans[next], next});
      }
    }
  }
  return ans[N] == 1e9 ? -1 : ans[N];
  // return -1;
}

int sol(){
  getInput();
  int temp = dijkstra(-1);
  int maxTime = -1;
  for(int i = 0; i < M; i++){
    int blocked = dijkstra(i);
    if(blocked == -1) return -1;
    maxTime = max(maxTime, blocked - temp);
  }
  return maxTime;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cout<<sol();
}