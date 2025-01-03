#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n,m;
vector<int>v[100100];
queue<int>q;
bool visited[10001];
int hackedCnt[100100];

void getInput(){
  cin>>n>>m;
  while(m--){
    int a,b;
    cin>>a>>b;
    v[b].push_back(a);
  }
}

int bfs(int a){
  fill(visited, visited+n+1, false);
  int hacked = 0;
  q.push(a);
  visited[a] = true;

  while(!q.empty()){
    int node = q.front();
    q.pop();
    hacked++;

    for(int i = 0; i < v[node].size(); i++){
      int next = v[node][i];
      if(visited[next]) continue;
      visited[next] = true;
      q.push(next);
    }
  }
  return hacked;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  getInput();
  
  int maxHack = 0;
  for(int i = 1; i <= n; i++){
    hackedCnt[i] = bfs(i);
    maxHack = max(maxHack, hackedCnt[i]);
  }

  for(int i = 1; i <= n; i++){
    if(hackedCnt[i] == maxHack){
      cout<<i<<" ";
    }
  }
  return 0;
}