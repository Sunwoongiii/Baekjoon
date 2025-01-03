#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <math.h>
#include <tuple>

using namespace std;
int n,m,x;
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;//value, node
bool visited[1001];
vector<pair<int,int>>v[10001];//node, value
vector<int>totalTime;
int ansGo[1001];
int ansBack[1001];


void resetGo(){
  for(int i = 1; i <= n; i++){
    ansGo[i] = 2e9;
    visited[i] = false;
  }
  while(!pq.empty()) pq.pop();
}

void resetBack(){
  for(int i = 1; i <= n; i++){
    ansBack[i] = 2e9;
    visited[i] = false;
  }
  while(!pq.empty()) pq.pop();
}

void dijkstraGo(int start){
  pq.push({0,start});
  ansGo[start] = 0;

  while(!pq.empty()){
    int value = pq.top().first;
    int node = pq.top().second;
    pq.pop();

    if(visited[node]) continue;
    visited[node] = true;

    for(int i = 0; i < v[node].size(); i++){
      int next = v[node][i].first;
      int cost = v[node][i].second;

      if(visited[next])continue;
      if(ansGo[next] > ansGo[node] + cost){
        ansGo[next] = ansGo[node] + cost;
        pq.push({ansGo[next], next});
      }
    }
  }
}

void dijkstraBack(int end){
  pq.push({0,end});
  ansBack[end] = 0;

  while(!pq.empty()){
    int value = pq.top().first;
    int node = pq.top().second;
    pq.pop();

    if(visited[node])continue;
    visited[node] = true;

    for(int i = 0; i < v[node].size(); i++){
      int next = v[node][i].first;
      int cost = v[node][i].second;

      if(visited[next])continue;
      if(ansBack[next] > ansBack[node] + cost){
        ansBack[next] = ansBack[node] + cost;
        pq.push({ansBack[next], next});
      }
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin>>n>>m>>x;
  for(int i = 1; i <= m; i++){
    int a,b,c;
    cin>>a>>b>>c;
    v[a].push_back({b,c});
  }

  for(int i = 1; i <= n; i++){
    resetGo();
    dijkstraGo(i);
    resetBack();
    dijkstraBack(x);
    totalTime.push_back(ansGo[x] + ansBack[i]);
  }
  cout<<*max_element(totalTime.begin(), totalTime.end());
  return 0;
}