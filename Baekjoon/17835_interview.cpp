#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>
using namespace std;
using ll = long long;

int n,m,k;
vector<pair<ll,int>>v[500500];
vector<int>interview;

void getInput(){
  int a,b;
  ll c;
  cin>>n>>m>>k;
  for(int i = 0; i < m; i++){
    cin>>a>>b>>c;
    v[a].push_back({c,b});
    v[b].push_back({c,a});
  }
  for(int i = 0; i < k; i++){
    cin>>a;
    interview.push_back(a);
  }
}

vector<ll> dijkstra(int start){
  vector<ll>ans(n+1, LLONG_MIN);
  priority_queue<pair<ll,int>>pq;
  pq.push({0,start});
  ans[start] = 0;

  while(!pq.empty()){
    ll value = pq.top().first;
    int node = pq.top().second;
    pq.pop();

    if(value < ans[node])continue;

    for(int i = 0; i < v[node].size(); i++){
      ll cost = v[node][i].first;
      int next = v[node][i].second;

      if(ans[next] < ans[node] + cost){
        ans[next] = ans[node] + cost;
        pq.push({ans[next], next});
      }
    }
  }

  for(int i = 1; i <= n; i++){
    if(ans[i] == LLONG_MIN)ans[i] = 0;
  }
  return ans;
}

void sol(){
  getInput();
  vector<ll>ans = dijkstra(interview[0]);

  for(int i = 1; i < interview.size(); i++){
    vector<ll>compare = dijkstra(interview[i]);
    for(int j = 1; j<= n; j++){
      ans[j] = max(ans[j], compare[j]);
    }
  }

  ll maxDist = INT_MIN;
  int minNode = -1;
  for(int i = 1; i <= n; i++){
    if(ans[i] > maxDist){
      maxDist = ans[i];
      minNode = i;
    }
    else if(ans[i] == maxDist && i < minNode) minNode = i;
  }
  cout<<maxDist<<'\n'<<minNode;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  sol();
}