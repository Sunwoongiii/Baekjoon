#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <math.h>
using namespace std;

int m,n;
int day = 0;
int tomato[1010][1010];
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
queue<pair<int,int>>q;

bool Inside(int nx, int ny){
  return(0<= nx && 0 <= ny && nx <n && ny < m);
}

void bfs(){
  while(!q.empty()){
    int x = q.front().first;
    int y = q.front().second;
    q.pop();

    for(int i = 0; i<4; i++){
      int nx = x+dx[i];
      int ny = y+dy[i];

      if(Inside(nx, ny) == 1 && tomato[nx][ny] == 0){
        tomato[nx][ny] = tomato[x][y] + 1;
        q.push({nx, ny});
      }      
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin>>m>>n;
  for(int i = 0; i <n; i++){
    for(int j=0; j<m;j++){
      cin>>tomato[i][j];
      if(tomato[i][j] == 1){
        q.push({i,j});
      }
    }
  }
  bfs();

  for(int i = 0; i<n;i++){
    for(int j=0; j<m;j++){
      if(tomato[i][j] == 0){
        cout<<-1;
        return 0;
      }
      if(day < tomato[i][j]){
        day = tomato[i][j];
      }
    }
  }
  cout<<day-1;
  return 0;
}