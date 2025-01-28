#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int a,k;
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;

int bfs(){
  cin>>a>>k;
  pq.push({0,a});
  while(!pq.empty()){
    int dist = pq.top().first;
    int node = pq.top().second;
    pq.pop();

    if(node == k)return dist;
    if(node * 2 <= k){
      pq.push({dist+1, node*2});
    }
    if(node + 1 <= k){
      pq.push({dist+1, node+1});
    }
  }
  return -1;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cout<<bfs();
}