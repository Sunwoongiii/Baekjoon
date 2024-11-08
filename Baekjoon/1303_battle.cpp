#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n,m;
int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};
bool visited[101][101];
queue<pair<int,int>>q;
int cnt=0,set=0;
char miro[101][101];

bool isInside(int a, int b){
  return(a>=0&&b>=0&&a<n&&b<m);
}

void getInput(){
  cin>>n>>m;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      cin>>miro[i][j];
      if(miro[i][j] == 'B')
    }
  }
}

int bfsB(){
  cnt = 0;
  while(!q.empty())
  int x = q.front().first;
  int y = q.front().second;
  q.pop();

  for(int i = 0; i < 4; i++){
    int nx = x + dx[i];
    int ny = y + dy[i];

    if(isInside(nx,ny) && !visited[nx][ny] && miro[nx][ny] == 'B'){
      q.push({nx,ny});
      cnt++;
    }
  }
  return cnt;
}

int bfsW(){
  cnt = 0;
  while(!q.empty())
  int x = q.front().first;
  int y = q.front().second;
  q.pop();

  for(int i = 0; i < 4; i++){
    int nx = x + dx[i];
    int ny = y + dy[i];

    if(isInside(nx,ny) && !visited[nx][ny] && miro[nx][ny] == 'W'){
      q.push({nx,ny});
      cnt++;
    }
  }
  return cnt;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  getInput();

}