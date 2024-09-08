#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;
#define INF 1000000000

int ans;
int n,m,r,a,b,l;
int local[101];
int d[101];
vector<pair<int,int>>v[101];

void dijkstra(int start){
  int cnt = 0; 
  queue<int>q;
  for(int i = 1; i<= n; i++){
    d[i] = INF;
  }
  d[start] = 0;
  q.push(start);

  while(!q.empty()){
    int node = q.front();
    int dist = d[node];
    q.pop();

    for(int i = 0; i < v[node].size(); i++){
      int next = v[node][i].first;
      int nextDist = v[node][i].second;

      if(d[next] > dist + nextDist){
        d[next] = dist + nextDist;
        q.push(next);
      }
    }
  }
  for(int i = 1; i <= n; i++) if(d[i] <= m) cnt += local[i];
  
  ans = max(ans,cnt);
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin>>n>>m>>r;
  for(int i = 1; i <= n;i++) cin>>local[i];
  for(int i = 0; i < r; i++){
    cin>>a>>b>>l;
    v[a].push_back({b,l});
    v[b].push_back({a,l});
  }
  for(int i = 1; i <= n; i++){
    dijkstra(i);
  }
  cout<<ans;
  return 0;
}