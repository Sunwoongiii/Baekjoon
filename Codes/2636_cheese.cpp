#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int n,m,result,ans = 0;
int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};
int miro[101][101];
bool visited[101][101];
queue<pair<int,int>>q;

bool isInside(int a, int b){
  return (a>=0&&b>=0&&a<n&&b<m);
}

bool bfs(){
  visited[0][0] = true;
  int cnt = 0;
  q.push({0,0});
  ans++;

  while(!q.empty()){
    int x = q.front().first;
    int y = q.front().second;
    q.pop();

    for(int i = 0; i < 4; i++){
      int nx = x + dx[i];
      int ny = y + dy[i];

      if(isInside(nx,ny) && !visited[nx][ny]){
        if(miro[nx][ny] == 0) q.push({nx,ny});
        else{
          miro[nx][ny] = 0;
          cnt++;
        }
        visited[nx][ny] = true;
      }
    }
  }
  if(cnt == 0){
    cout<<--ans<<"\n"<<result;
    return true;
  }
  else{
    result = cnt;
    return false;
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin>>n>>m;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++)cin>>miro[i][j];
  }

  while(true){
    if(bfs())break;
    memset(visited, false, sizeof(visited));
  }
  return 0;
}