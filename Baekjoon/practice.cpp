#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int n,m,day=0;
int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};
int miro[1010][1010];
int ans[1010][1010];
queue<pair<int,int>>q;

bool isInside(int a, int b){
  return(a>=0&&b>=0&&a<n&&b<m);
}

void getInput(){
  cin>>m>>n;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      cin>>miro[i][j];
      ans[i][j] = miro[i][j];
      if(ans[i][j] == 1){
        q.push({i,j});
      }
    }
  }
}

int bfs(){
  while(!q.empty()){
    int x = q.front().first;
    int y = q.front().second;
    q.pop();

    for(int i = 0; i < 4; i++){
      int nx = x + dx[i];
      int ny = y + dy[i];

      if(isInside(nx,ny) && ans[nx][ny] == 0){
        ans[nx][ny] = ans[x][y] + 1;
        q.push({nx,ny});
      }
    }
  }

  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      if(ans[i][j] == 0) return -1;
      if(day < ans[i][j]) day = ans[i][j];
    }
  }
  return day-1;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  getInput();
  cout<<bfs();

  return 0;
}