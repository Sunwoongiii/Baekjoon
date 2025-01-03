#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <math.h>
#include <tuple>

using namespace std;

int n,m,h;
int tomato[101][101][101];
int ans[101][101][101];
int dx[6] = {0,0,0,0,-1,1};
int dy[6] = {0,0,1,-1,0,0};
int dz[6] = {1,-1,0,0,0,0};
int day = 0;
queue<tuple<int,int,int>>q;

bool isInside(int a, int b, int c){
  return(a >= 0 && a < n && b >= 0 && b < m && c >= 0 && c < h);
}

void bfs(){
  while(!q.empty()){
    int x = get<0>(q.front());
    int y = get<1>(q.front());
    int z = get<2>(q.front());
    q.pop();

    for(int i = 0; i < 6; i ++){
      int nx = x + dx[i];
      int ny = y + dy[i];
      int nz = z + dz[i];

      if(isInside(nx,ny,nz) && tomato[nx][ny][nz] == 0){
        tomato[nx][ny][nz] = 1;
        ans[nx][ny][nz] = ans[x][y][z] + 1;
        q.push({nx,ny,nz});
      }
    }
  }
}


int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin>>m>>n>>h;
  for(int k = 0; k < h; k++){
    for(int i = 0; i < n; i++){
      for(int j = 0; j < m; j++){
        cin>>tomato[i][j][k];
        ans[i][j][k] = tomato[i][j][k];
        if(tomato[i][j][k] == 1) q.push({i,j,k});
      }
    }
  }
  bfs();
  for(int k = 0; k < h; k++){
    for(int i = 0; i < n; i++){
      for(int j = 0; j < m; j++){
        if(ans[i][j][k] == 0){
          cout<<-1;
          return 0;
        }
        day = max(day, ans[i][j][k]);
      }
    }
  }
  cout<<day-1;
  return 0;
}