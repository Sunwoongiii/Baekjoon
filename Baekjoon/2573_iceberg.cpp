#include <iostream>
#include <vector>
#include <queue>
#include <array>
#include <utility>

using namespace std;

int miro[303][303];
int around[303][303];
int n,m,year;
bool visited[303][303];
int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};
queue<pair<int,int>>q;

bool isInside(int x, int y){
  return (x >= 0 && y >= 0 && x < n && y < m);
}

void sideZero(){
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      int cnt = 0;
      int x = i, y = j;

      if(miro[i][j] == 0) continue;

      for(int k = 0; k < 4; k++){
        int nx = x + dx[k]; 
        int ny = y + dy[k];

        if(isInside(nx, ny) && miro[nx][ny] == 0)cnt++;
      }
      around[x][y] = cnt;
    }
  }
}

void bfs(int a, int b){
  q.push({a,b});
  visited[a][b] = true;
  while(!q.empty()){
    int x = q.front().first;
    int y = q.front().second;
    q.pop();

    for(int i = 0; i < 4; i++){
      int nx = x + dx[i];
      int ny = y + dy[i];

      if(isInside(nx, ny) && miro[nx][ny] > 0 && !visited[nx][ny]){
        visited[nx][ny] = true;
        q.push({nx,ny});
      }
    }    
  }
}

int countCluster(){
  int cluster = 0;
  for(int i =0; i < n; i++){
    for(int j = 0; j < m; j++){
      visited[i][j] = false;
    }
  }
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      if(miro[i][j] > 0 && !visited[i][j]){
        cluster++;
        bfs(i,j);
      }
    }
  }
  return cluster;
}

void melting(){
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      int afterMelt = max(miro[i][j] - around[i][j], 0);
      miro[i][j] = afterMelt;
    }
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  
  cin>>n>>m;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      cin>>miro[i][j];
    }
  }

  while(true){
    sideZero();
    melting();
    year++;

    int clusterCnt = countCluster();

    if(clusterCnt == 0){
      cout<<0;
      return 0;
    }
    if(clusterCnt > 1){
      cout<<year;
      return 0;
    }
  }
}