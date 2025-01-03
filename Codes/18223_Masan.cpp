#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int V,e,p;
vector<pair<int,int>>v[10101];

void getInput(){
  cin>>V>>e>>p;
  for(int i = 0; i < e; i++){
    int a,b,c;
    cin>>a>>b>>c;
    v[a].push_back({c,b});
    v[b].push_back({c,a});
  }
}

int dijkstra(int start, int end){
  priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
  vector<int>ans(V+1, 1e9);

  pq.push({0,start});
  ans[start] = 0;

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
  return ans[end] == 1e9 ? -1 : ans[end];
}

void sol(){
  getInput();

  int one_to_masan = dijkstra(1,V);
  int one_to_gunwoo = dijkstra(1,p);
  int gunwoo_to_masan = dijkstra(p,V);

  if(one_to_masan != -1 && one_to_masan == one_to_gunwoo + gunwoo_to_masan){
    cout<<"SAVE HIM";
  }
  else{
    cout<<"GOOD BYE";
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  sol();
}