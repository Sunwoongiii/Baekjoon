#include <iostream>
#include <queue>
#include <vector>
#define inf 100001

using namespace std;

int n,k;
bool visited[inf];
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;

int dijkstra(){
  pq.push({0,n});
  while(!pq.empty()){
    int value = pq.top().first;
    int node = pq.top().second;
    pq.pop();

    if(node == k) return value;

    if(visited[node])continue;
    visited[node] = true;

    if(node * 2 < inf){
      pq.push({value+1, node*2});
      visited[node] = true;
    }

    if(node +1 < inf){
      pq.push({value+1, node+1});
      visited[node] = true;
    }

    if(node -1 >= 0){
      pq.push({value+1, node-1});
      visited[node] = true;
    }
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin>>n>>k;
  cout<<dijkstra()<<"\n";
}