#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int n,e,m,s;
int mx,sy;
int node;
int dist[2][10010];
vector<vector<pair<int,int>>>edges;
vector<int>house;

void dijkstra(int start, int state){
  for(int i = 0; i < n+5; i++)dist[state][i] = 1e9;
  priority_queue<pair<int,int>>pq;
  pq.push({0,start});

  while(!pq.empty()){
    int here = pq.top().second;
    int cost = -pq.top().first;
    pq.pop();

    if(dist[state][here] < cost)continue;

    for(int i = 0; i < edges[here].size(); i++){
      int next = edges[here][i].first;
      int next_cost = cost + edges[here][i].second;

      if(state == 0 && next_cost > mx)continue;
      else if(state == 1 && next_cost > sy)continue;

      if(dist[state][next] > next_cost){
        dist[state][next] = next_cost;
        pq.push({-next_cost, next});
      }
    }
  }
}

void sol(){
  cin>>n>>e;
  edges.resize(n+5);
  house.resize(n+5);

  int a,b,c;
  for(int i = 0; i < e; i++){
    cin>>a>>b>>c;
    edges[b].push_back({a,c});
    edges[a].push_back({b,c});
  }
  cin>>m>>mx;
  for(int i = 0; i < m; i++){
    cin>>node;
    edges[n+1].push_back({node, 0});
    house[node] = -1;
  }
  cin>>s>>sy;
  for(int i = 0; i < s; i++){
    cin>>node;
    edges[n+2].push_back({node, 0});
    house[node] = -1;
  }

  dijkstra(n+1,0);
  dijkstra(n+2,1);

  int ans = 1e9;
  for(int i = 1; i <= n; i++){
    if(house[i] == -1)continue;
    int sum = dist[0][i] + dist[1][i];
    if(ans>sum)ans = sum;
  }
  if(ans == 1e9)cout<<-1;
  else cout<<ans;
}

int main(void){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  sol();
}