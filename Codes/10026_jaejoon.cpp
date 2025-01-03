#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <math.h>

using namespace std;
char pic[101][101];
bool visited[101][101] = {false};
int n;
int normalCnt = 0, blindCnt = 0;
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
bool colorBlind;
queue<pair<int,int>>q;

bool isInside(int a, int b){
  return(a >= 0 && a < n && b >= 0 && b < n);
}

void reset(){
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      visited[i][j] = false;
    }
  }
  while(!q.empty()) q.pop();
}

void bfs(int a, int b, char color, bool colorBlind){
  q.push({a,b});
  visited[a][b] = true;

  while(!q.empty()){
    int x = q.front().first;
    int y = q.front().second;
    q.pop();

    for(int i = 0; i < 4; i++){
      int nx = x + dx[i];
      int ny = y + dy[i];

      if(isInside(nx,ny) && !visited[nx][ny]){
        if(colorBlind){
          if((color == 'R' || color == 'G') && (pic[nx][ny] == 'R' || pic[nx][ny] == 'G')){
            q.push({nx,ny});
            visited[nx][ny] = true;
          }
          else if(pic[nx][ny] == color){
            q.push({nx,ny});
            visited[nx][ny] = true;
          }
        }
        else{
          if(pic[nx][ny] == color){
            q.push({nx,ny});
            visited[nx][ny] = true;
          }
        }
      }
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin>>n;
  for(int i = 0; i < n; i ++){
    for(int j =  0; j < n; j++){
      cin>>pic[i][j];
    }
  }

  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      if(!visited[i][j]){
        bfs(i, j, pic[i][j], false);
        normalCnt++;
      }
    }
  }
  reset();
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      if(!visited[i][j]){
        bfs(i, j, pic[i][j], true);
        blindCnt++;
      }
    }
  }
  cout<<normalCnt<<" "<<blindCnt;
  return 0;
}