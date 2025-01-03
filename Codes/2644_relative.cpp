#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
queue<int>q;
vector<int>v[101];
bool visited[101];
int ans[101];
int tX, tY;

int bfs(){
  q.push(tX);
  visited[tX] = true;

  while(!q.empty()){
    int node = q.front();
    q.pop();

    if(node == tY) return ans[node];

    for(int i = 0 ; i < v[node].size(); i++){
      int next = v[node][i];
      if(!visited[next]){
        ans[next] = ans[node] + 1;
        visited[next] = true;
        q.push(next);
      }
    }
  }
  return -1;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin>>n>>tX>>tY>>m;
  for(int i = 0; i < m; i++){
    int a,b;
    cin>>a>>b;
    v[a].push_back(b);
    v[b].push_back(a);
  }

  cout<<bfs();
  return 0;
}