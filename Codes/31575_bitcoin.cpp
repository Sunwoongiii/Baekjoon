#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n,m;
int dx[2] = {0,1};
int dy[2] = {1,0};
int miro[303][303];
bool visited[303][330];

void getInput(){
  cin>>m>>n;
  for(int i = 0; i < n; i++){
    for(int j = 0; j <  m; j++){
      cin>>miro[i][j];
    }
  }
}

bool isInside(int a, int b){
  return(a>=0&&b>=0&&a<n&&b<m);
}

bool bfs(){
  queue<pair<int,int>>q;
  q.push({0,0});
  visited[0][0] = true;

  while(!q.empty()){
    int x = q.front().first;
    int y = q.front().second;
    q.pop();

    if(x == n-1 && y == m-1)return true;

    for(int i = 0 ; i < 2; i++){
      int nx = x + dx[i];
      int ny = y + dy[i];

      if(isInside(nx,ny)&&!visited[nx][ny]&&miro[nx][ny] == 1){
        q.push({nx,ny});
        visited[nx][ny] = true;
      }
    }
  }
  return false;
}

void sol(){
  getInput();
  if(bfs())cout<<"Yes";
  else cout<<"No";
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  sol();  
}