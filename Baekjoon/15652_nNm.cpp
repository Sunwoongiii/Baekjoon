#include <iostream>
using namespace std;

int n,m;
int ans[10];
bool visited[10];

void dfs(int num, int cnt);

void sol(){
  cin>>n>>m;
  dfs(1,0);
}

void dfs(int num, int cnt){
  if(cnt == m){
    for(int i = 0; i < m; i++)cout<<ans[i]<<' ';
    cout<<'\n';
    return;
  }
  for(int i = num; i <= n; i++){
    visited[i] = true;
    ans[cnt] = i;
    dfs(i,cnt+1);
    visited[i] = false;
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  sol();
}