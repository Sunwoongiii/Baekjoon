#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
using ll = long long;

ll n, m,k,idx;
vector<pair<ll,ll>> adj[100001];
vector<ll> interview;
ll dist[100001];

void intput(){
  cin>>n>>m>>k;
  ll u,v,c;
  for(int i = 0; i < m; i ++){
    cin>>u>>v>>c;
    adj[v].push_back({c,u});
  }
  for(int i = 0; i < k; i++){
    cin>>u;
    interview.push_back(u);
  }
  for(int i = 1; i <=n;i++){
    dist[i] = 1e18;
  }
}

void reverseDijkstra(){
  ll max_cost = 0;
  priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> pq;
  for(int i = 0; i < k; i++){
    pq.push({0,interview[i]});
    dist[interview[i]] = 0;
  }

  while(!pq.empty()){
    ll node = pq.top().second;
    ll value = pq.top().first;  
    pq.pop();

    if(dist[node] < value) continue;
    for(int i = 0; i < adj[node].size(); i++){
      ll next = adj[node][i].second;
      ll cost = adj[node][i].first + value;

      if(dist[next] > cost){
        dist[next] = cost;
        pq.push({cost,next});
      }
    }
  }
  for(int i = 1; i <= n; i++){
    if(max_cost < dist[i]){
      max_cost = dist[i];
      idx = i;
    }
  }
  cout<<idx<<"\n"<<max_cost;
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  intput();
  reverseDijkstra();
  return 0;
}