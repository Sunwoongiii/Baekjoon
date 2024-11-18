#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;

int K,w,h;
int miro[202][202];
int hx[8] = {-2, -1, +1, +2, +2, +1, -1, -2};
int hy[8] = {+1, +2, +2, +1, -1, -2, -2, -1};
int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};
bool visited[202][202][31];
queue<tuple<int,int,int,int>>q;

void getInput(){
  cin>>K>>w>>h;
  for(int i = 0; i < h; i++){
    for(int j = 0; j < w; j++){
      cin>>miro[i][j];
    }
  }
}

bool isInside(int a, int b){
  return(a>=0&&b>=0&&a<h&&b<w);
}

int bfs(){
  q.push({0,0,0,0});
  for(int i = 0; i < K; i++)visited[0][0][i] = true;

  while(!q.empty()){
    int dist, x, y, hMove;
    tie(dist, x, y, hMove) = q.front();
    q.pop();

    if(x == h-1 && y == w-1)return dist;

    for(int i = 0; i < 4; i++){
      int nx = x + dx[i];
      int ny = y + dy[i];

      if(isInside(nx,ny) && miro[nx][ny] == 0 && !visited[nx][ny][hMove]){
        visited[nx][ny][hMove] = true;
        q.push({dist+1, nx, ny, hMove});
      }
    }

    if(hMove < K){
      for(int i = 0; i < 8; i++){
        int nx = x + hx[i];
        int ny = y + hy[i];

        if(isInside(nx,ny) && miro[nx][ny] == 0 && !visited[nx][ny][hMove+1]){
          visited[nx][ny][hMove+1] = true;
          q.push({dist+1, nx, ny, hMove+1});
        }
      }
    }
  }
  return -1;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  getInput();
  cout<<bfs();
}