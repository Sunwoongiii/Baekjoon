#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

int n,m,r;
priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>>>pq;
bool visited[101];
vector<tuple<int,int,int>>v[101];
int ans[101];
int item[101];
vector<int> maxi;
//pq: value, node, item

void reset(){
  for(int i = 0; i < n; i++){
    ans[i] = 2e9;
  }
  while(!pq.empty()) pq.pop();
}

int dijkstra(){
  for(int i = 0; i < n; i++){
    pq.push({0, i, item[i]});
    while(!pq.empty()){
      int value, node, its;
      tie(value, node, its) = pq.top();
      pq.pop();

      if(visited[node]) continue;
      visited[node] = true;
      if()
    }
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);


}