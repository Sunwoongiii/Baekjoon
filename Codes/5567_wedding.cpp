#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n,m,cnt=0;
vector<int>v[10010];
queue<int>q;
bool visited[505];

void getInput(){
  cin>>n>>m;
  for(int i = 0; i < m; i++){
    int a,b;
    cin>>a>>b;
    v[a].push_back(b);
    v[b].push_back(a);
  }
}

int bfs(){
  q.push(1);
  visited[1] = true;

  while(!q.empty()){
    int node = q.front();
    q.pop();

    for(int i = 0; i < v[node].size(); i++){
      int next = v[node][i];

      if(visited[next])continue;
      cnt++;
      visited[next] = true;
      q.push(next);
    }
    return cnt;
  }
  return -1;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  getInput();
  int result = bfs();
  if(result == 1 || result == -1){
    cout<<0;
  }
  else cout<<result;

  return 0;
}