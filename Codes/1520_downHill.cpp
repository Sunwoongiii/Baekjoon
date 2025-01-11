#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int n,m;
int miro[505][505];
int ans[505][505];
int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};
queue<pair<int,int>>q;

void getInput(){
  cin>>n>>m;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      cin>>miro[i][j];
      ans[i][j] = -1;
    }
  }
}

bool isInside(int a, int b){
  return(a>=0&&b>=0&&a<n&&b<m);
}

int dfs(int x, int y){
  if(x == n-1 && y == m-1)return 1;
  if(ans[x][y] != -1)return ans[x][y];

  ans[x][y] = 0;
  for(int i = 0; i < 4; i++){
    int nx = x + dx[i];
    int ny = y + dy[i];

    if(isInside(nx,ny) && miro[nx][ny] < miro[x][y]){
      ans[x][y] += dfs(nx,ny);
    }
  }
  return ans[x][y];
}

void sol(){
  getInput();
  cout<<dfs(0,0);
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  sol();
}