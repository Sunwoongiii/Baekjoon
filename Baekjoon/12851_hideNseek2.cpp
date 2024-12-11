#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int dist[100100];
int cnt[100100];
int n, k;
queue<int> q;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  
  cin>>n>>k;
  if(n == k){
    cout<<0<<'\n'<<1;
    return 0;
  }

  fill(dist, dist+100100, -1);
  dist[n] = 0;
  cnt[n] = 1;
  q.push(n);

  while(!q.empty()){
    int node = q.front();
    q.pop();

    for(int next : {node-1, node+1, node*2}){
      if(next < 0 || next > 100000) continue;
      if(dist[next] != -1){
        if(dist[node] + 1 == dist[next]) cnt[next] += cnt[node];
      }
      else{
        dist[next] = dist[node] + 1;
        cnt[next] = cnt[node];
        q.push(next);
      }
    }
  }
  cout<<dist[k]<<'\n'<<cnt[k];
}