#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
using ll = long long;

int n,m,t1,t2;
ll maxW = -1;
bool visited[100001];
vector<pair<int,ll>>v[100100];
queue<int>q;

void getInput(){
  int a,b;
  ll c;
  cin>>n>>m;
  for(int i = 0; i < m; i++){
    cin>>a>>b>>c;
    v[a].push_back({c,b});
    v[b].push_back({c,a});
    maxW = max(maxW, c);
  }
  cin>>t1>>t2;
}

void reset(){
  fill(visited, visited + n + 1, false);
  while(!q.empty())q.pop();
}

bool bfs(ll w){//parameter : weight limit
  reset();
  q.push(t1);
  visited[t1] = true;
  
  while(!q.empty()){
    int node = q.front();
    q.pop();

    if(node == t2)return true;

    for(int i = 0; i < v[node].size(); i++){
      ll limit = v[node][i].first;
      int next = v[node][i].second;

      if(limit >= w && !visited[next]){
        visited[next] = true;
        q.push(next);
      }
    }
  }
  return false;
}

void sol(){
  getInput();
  ll maxi = -1;
  ll front = 1;
  ll back = maxW;

  while(front <= back){
    ll mid = (front + back) / 2;

    if(bfs(mid)){
      front = mid+1;
      maxi = mid;
    }
    else{
      back = mid-1;
    }
  }

  cout<<maxi;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  sol();
}