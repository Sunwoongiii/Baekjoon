#include <iostream>
#include <queue>
#include <vector>
#include <tuple>
using namespace std;

int L,R,C,ex,ey,ez; // L: z, R: x, C: y
char miro[33][33][33];
int ans[33][33][33];
int dx[6] = {0,0,0,0,-1,1};
int dy[6] = {0,0,-1,1,0,0};
int dz[6] = {-1,1,0,0,0,0};
queue<tuple<int,int,int>>q;

bool getInput(){
  cin>>L>>R>>C;

  if(L == 0 && R == 0 && C == 0)return false;
  else{
    for(int i = 0; i < L; i++){
      for(int j = 0; j < R; j++){
        for(int k = 0;  k < C; k++){
          cin>>miro[i][j][k];

          if(miro[i][j][k] == 'S'){
            q.push({i,j,k});
          }

          if(miro[i][j][k] == 'E'){
            ez = i;
            ex = j;
            ey = k;
          }
          ans[i][j][k] = 0;
        }
      }
    }
  }
  return true;
}

bool isInside(int a, int b, int c){//x,y,z 순서
  return (a >= 0 && b >= 0 && c >= 0 && a < R && b < C && c < L);
}

int bfs(){
  if(miro[ez][ex][ey] == 'S'){
    return 0;
  }

  while(!q.empty()){
    int x,y,z;
    tie(z,x,y) = q.front();
    q.pop();

    for(int i = 0; i < 6; i++){
      int nx = x + dx[i];
      int ny = y + dy[i];
      int nz = z + dz[i];

      if(isInside(nx,ny,nz) && miro[nz][nx][ny] != '#' && ans[nz][nx][ny] == 0){
        ans[nz][nx][ny] = ans[z][x][y] + 1;
        if(nx == ex && ny == ey && nz == ez){
          return ans[nz][nx][ny];
        }
        q.push({nz,nx,ny});
      }
    }
  }
  return -1;
}

void sol(){
  while(true){
    if(getInput()){
      int dist = bfs();

      if(dist == -1)cout<<"Trapped!\n";
      else cout<<"Escaped in "<<dist<<" minute(s).\n";
      while(!q.empty()) q.pop();
    }
    else{
      return;
    }
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  sol();
}