#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>

using namespace std;

int T, t;
int n,d,c;
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
vector<pair<int,int>>v[100001];
int ans[100001];

void dijkstra(){
  ans[c] = 0;
  pq.push({0, c});
  while(!pq.empty()){
    
    int value = pq.top().first;
    int node = pq.top().second;
    pq.pop();
    if(ans[node] < value) continue;

    for(int i = 0; i < v[node].size(); i++){
      int cost = v[node][i].first+value;
      int next = v[node][i].second;

      if(cost < ans[next]){
        ans[next] = cost;
        pq.push({ans[next], next});
      }
    }
  }
  int com = 0, t = 0;
  for(int i = 1; i <= n; i++){
    if(ans[i] == INT32_MAX) continue;
    
    com++;
    t = max(t,ans[i]);
  }
  cout<<com<<" "<<t<<"\n";
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin>>T;
  while(T--){
    cin>>n>>d>>c;
    fill(ans, ans+n+1, INT32_MAX);
    for(int i = 0; i <= n; i++)v[i].clear();
    
    for(int i = 0; i < d; i++){
      int a,b,s;
      cin>>a>>b>>s;
      v[b].push_back({s,a});
    }
    dijkstra();
  }
}