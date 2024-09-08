#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <math.h>

using namespace std;
int island = 0;
int w,h;
int map[55][55];
bool visited[55][55] = {false};
int dx[8] = {0, 0,-1,1,1,-1, 1,-1};
int dy[8] = {1,-1,0,0, 1, 1,-1,-1};
queue<pair<int,int>>q;

bool isInside(int a, int b){
  return (0<=a && 0<= b && a<h && b<w);
}

void bfs(int a, int b){
  q.push({a,b});
  visited[a][b] = true;

  while(!q.empty()){
    int x = q.front().first;
    int y = q.front().second;
    q.pop();

    for(int i = 0; i< 8; i++){
      int nx = x + dx[i];
      int ny = y + dy[i];

      if(isInside(nx, ny) == 1 && !visited[nx][ny] && map[nx][ny] == 1){
        q.push({nx, ny});
        visited[nx][ny] = true;
      }
    }
  }
}


int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  while(true){
    cin>>w>>h;
    if(w == 0 && h == 0) break;

    for(int i=0; i<h; i++){
      for(int j=0; j<w; j++){
        cin>>map[i][j];
        visited[i][j] = false;
      }
    }

    island = 0;
    for(int i = 0; i < h; i++){
      for(int j = 0; j < w; j++){
        if(map[i][j] == 1 && !visited[i][j]){
          bfs(i, j);
          island++;
        }
      }
    }
    cout<<island<<"\n";
  }
  return 0;
}