#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <algorithm>
using namespace std;

int n,m,k;
bool visited[1010][1010][11];
int ans[1010][1010][11];
char miro[1010][1010];
int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};
queue<tuple<int,int,int,bool>>q;// x, y, 부순 벽 수, 낮&밤 구분

void getInput(){
  cin>>n>>m>>k;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      cin>>miro[i][j];
    }
  }
}

bool isInside(int a, int b){
  return(a>=0&&b>=0&&a<n&&b<m);
}

int bfs(){
  q.push({0,0,0,true});
  visited[0][0][0] = true;
  for(int i = 0; i <= k; i++)ans[0][0][i] = 1;
  
  while(!q.empty()){
    int x,y,smashedWall;
    bool isDay;
    tie(x,y,smashedWall,isDay) = q.front();
    q.pop();

    for(int i = 0; i < 4; i++){
      int nx = x + dx[i];
      int ny = y + dy[i];

      if(isInside(nx,ny)){
        if(miro[nx][ny] == '0' && !visited[nx][ny][smashedWall]){
          ans[nx][ny][smashedWall] = ans[x][y][smashedWall] + 1;
          visited[nx][ny][smashedWall] = true;
          q.push({nx,ny,smashedWall, !isDay});
        }

        if(miro[nx][ny] == '1' && !visited[nx][ny][smashedWall+1] && smashedWall < k && isDay){
          ans[nx][ny][smashedWall+1] = ans[x][y][smashedWall] + 1;
          visited[nx][ny][smashedWall+1] = true;
          q.push({nx,ny,smashedWall+1,!isDay});
        }

        if(miro[nx][ny] == '1' && !visited[nx][ny][smashedWall+1] && smashedWall < k && !isDay){
          ans[x][y][smashedWall]++;
          q.push({x,y,smashedWall, !isDay});
        }
      }
    }
  }

  int minMove = 1e9;// 최소이동거리 찾기
  for(int i = 0; i <= k; i++){
    if(ans[n-1][m-1][i] == 0) continue;
    minMove = min(minMove, ans[n-1][m-1][i]);
  }

  return minMove == 1e9 ? -1 : minMove;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  getInput();
  cout<<bfs();

  //디버깅용 씨발뭐가문제지
  // cout<<bfs()<<"\n\n";

  // for(int u = 0; u <= k; u++){
  //   cout<<"Smashed wall: "<<u<<'\n';
  //   for(int i = 0; i < n; i++){
  //     for(int j = 0; j < m; j++){
  //       cout<<ans[i][j][u]<<' ';
  //     }
  //     cout<<"\n";
  //   }
  //   cout<<"\n\n";
  // }
}