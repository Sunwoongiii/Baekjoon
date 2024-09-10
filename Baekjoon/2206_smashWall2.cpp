#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

int n,m;
queue<tuple<int,int,int,int>>q;//dist, x, y, if smashed?
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
char miro[1001][1001];
bool visited[1001][1001][2];

bool isInside(int x, int y){
  return(x > 0 && y > 0 && x <= n && y <= m);
}

int bfs(){
  q.push({1,1,1,0});
  visited[1][1][0] = true;
  
  while(!q.empty()){
    int dist, x, y, smashed;
    tie(dist, x, y, smashed) = q.front();
    q.pop();

    if(x == n && y == m) return dist;

    for(int i = 0; i < 4; i++){
      int nx = x + dx[i];
      int ny = y + dy[i];

      if(isInside(nx, ny)){
        if(miro[nx][ny] == '0' && !visited[nx][ny][smashed]){
          q.push({dist+1, nx, ny, smashed});
          visited[nx][ny][smashed] = true;
        }
        else if(miro[nx][ny] == '1' && !visited[nx][ny][1] && smashed == 0){
          q.push({dist+1, nx, ny, 1});
          visited[nx][ny][1] = true;
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

  cin>>n>>m;
  for(int i = 1; i <= n; i++){
    for(int j=1;j<=m;j++){
      cin>>miro[i][j];
    }
  }
  cout<<bfs();
}