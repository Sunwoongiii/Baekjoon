#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<int> v[100001];
queue<int>q;
bool visited[100001];
int ans[100001];

void bfs(){
  q.push(1);
  visited[1] = true;

  while(!q.empty()){
    int x = q.front();
    q.pop();

    for(int i = 0; i < v[x].size(); i++){
      int next = v[x][i];
      if(!visited[next]){
        ans[next] = x;
        visited[next] = true;
        q.push(next);
      }
    }
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin>>n;
  for(int i = 0; i < n-1 ; i++){
    int a,b;
    cin>>a>>b;
    v[a].push_back(b);
    v[b].push_back(a);
  }
  bfs();
  for(int i = 2; i <= n; i++){
    cout<<ans[i]<<"\n";
  }
  return 0;
}