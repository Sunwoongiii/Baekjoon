#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <math.h>

using namespace std;
int n,m,a,b;
int miro[1010][1010];
int ans[1010][1010] = {0};
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
bool visited[1010][1010] = {false};
queue<pair<int,int>>q;

bool isInside(int a, int b){
  return(a >= 0 && b >= 0 && a < n && b < m);
}

void bfs(){
  while(!q.empty()){
    int x = q.front().first;
    int y = q.front().second;
    q.pop();

    for(int i = 0; i < 4; i ++){
      int nx = x + dx[i];
      int ny = y + dy[i];

      if(isInside(nx, ny) && !visited[nx][ny] && miro[nx][ny] != 0){
        visited[nx][ny] = true;
        q.push({nx,ny});
        ans[nx][ny] = ans[x][y] +1;
      }
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin>>n>>m;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      cin>>miro[i][j];
      if(miro[i][j] == 2){
        a = i;
        b = j;
      }
    }
  }
  q.push({a, b});
  visited[a][b] = true;
  bfs();
  for(int i = 0; i < n; i++){
    for(int j = 0; j <m; j++){
      if(ans[i][j] == 0 && miro[i][j] != 0){
        ans[i][j] = -1;
      }
      ans[a][b] = 0;
      cout<<ans[i][j]<<" ";
    }
    cout<<"\n";
  }
}