#include <iostream>
#include <tuple>
#include <queue>
#include <vector>
using namespace std;

int n,m,k;
int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};
int ans[1010][1010][11];
char miro[1010][1010];
bool visited[1010][1010][11];
priority_queue<tuple<int,int,int,int>,vector<tuple<int,int,int,int>>,greater<tuple<int,int,int,int>>>pq;

bool isInside(int a, int b){
  return(a>=1&&b>=1&&a<=n&&b<=m);
}

void getInput(){
  cin>>n>>m>>k;
  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= m; j++){
      cin>>miro[i][j];
      for(int l = 0; l <= k; l++)ans[i][j][l] = 2e9;
    }
  }
}

int dijkstra(){
  pq.push({1,0,1,1});//이동거리, 부순 벽, x, y
  ans[1][1][0] = 0;
  visited[1][1][0] = true;

  while(!pq.empty()){
    int dist, smashed, x, y;
    tie(dist, smashed, x, y) = pq.top();
    pq.pop();

    if(x == n && y == m) return dist;

    for(int i = 0; i < 4; i++){
      int nx = x + dx[i];
      int ny = y + dy[i];

      if(isInside(nx,ny)){
        if(miro[nx][ny] == '0' && !visited[nx][ny][smashed] && ans[nx][ny][smashed] > dist + 1){
          ans[nx][ny][smashed] = dist+1;
          visited[nx][ny][smashed] = true;
          pq.push({ans[nx][ny][smashed], smashed, nx, ny});
        }
        else if(miro[nx][ny] == '1' && !visited[nx][ny][smashed+1] && smashed < k && ans[nx][ny][smashed] > dist+1){
          ans[nx][ny][smashed] = dist + 1;
          visited[nx][ny][smashed+1] = true;
          pq.push({ans[nx][ny][smashed], smashed+1, nx,ny});
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
  cout<<dijkstra();
}