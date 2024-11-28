#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <algorithm>
using namespace std;

int n,m,k;
char miro[1010][1010];
bool visited[1010][1010][11];
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

void getIput(){
  cin>>n>>m>>k;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++)cin>>miro[i][j];
  }
}

bool isInside(int a, int b){
  return(a>=0&&b>=0&&a<n&&b<m);
}

void BFS(int a, int b){
  queue<pair<tuple<int,int,int>,pair<int,bool>>> q;
  q.push({{a,b,1},{0, true}});
  visited[a][b][0] = true;

  while(!q.empty()){
    int x = get<0>(q.front().first);
    int y = get<1>(q.front().first);
    int cnt = get<2>(q.front().first);
    int wall = q.front().second.first;
    bool isDay = q.front().second.second;
    q.pop();

    if(x == n-1 && y == m-1){
      cout<<cnt;
      return;
    }

    for(int i = 0; i < 4; i++){
      int nx = x + dx[i];
      int ny = y + dy[i];

      if(isInside(nx,ny)){
        if(miro[nx][ny] == '0'){
          if(visited[nx][ny][wall] == false){
            visited[nx][ny][wall] = true;
            q.push({{nx,ny,cnt+1},{wall, !isDay}});
          }
        }
        else if(miro[nx][ny] == '1'){
          if(wall < k){
            if(visited[nx][ny][wall+1] == false){
              if(isDay){
                visited[nx][ny][wall+1] = true;
                q.push({{nx,ny,cnt+1},{wall+1, !isDay}});
              }
              else{
                q.push({{x,y,cnt+1},{wall, !isDay}});
              }
            }
          }
        }
      }
    }
  }
  cout<<-1;
}

void sol(){
  getIput();
  BFS(0,0);
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  sol();
}