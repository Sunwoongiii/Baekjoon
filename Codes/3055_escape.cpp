#include <iostream>
#include <queue>
using namespace std;

int n,m;
char miro[55][55];
int waterMap[55][55];
bool visited[55][55];
pair<int,int> S,D;
int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};
queue<pair<int,int>>q;

void getInput(){
  cin>>n>>m;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      cin>>miro[i][j];
      waterMap[i][j] = 1e9;

      if(miro[i][j] == 'S'){
        S.first = i;
        S.second = j;
      }else if(miro[i][j] == 'D'){
        D.first = i;
        D.second = j;
      }else if(miro[i][j] == '*'){
        q.push({i,j});
        waterMap[i][j] = 0;
      }
    }
  }
}

bool isInside(int a, int b){
  return(a>=0&&b>=0&&a<n&&b<m);
}

void waterBFS(){
  while(!q.empty()){
    int qSize = q.size();

    for(int s = 0; s < qSize; s++){
      int x = q.front().first;
      int y = q.front().second;
      q.pop();

      for(int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(isInside(nx,ny)){
          if(miro[nx][ny] == '.'){
            if(waterMap[nx][ny] > waterMap[x][y] + 1){
              waterMap[nx][ny] = waterMap[x][y] + 1;
              q.push({nx,ny});
            }
          }
        }
      }
    }
  }
}

int bfs(int a, int b){
  queue<pair<pair<int,int>,int>>Q;
  Q.push({{a,b},0});
  visited[a][b] = true;

  while(!Q.empty()){
    int x = Q.front().first.first;
    int y = Q.front().first.second;
    int dist = Q.front().second;
    Q.pop();

    if(x == D.first && y == D.second)return dist;

    for(int i = 0; i < 4; i++){
      int nx = x + dx[i];
      int ny = y + dy[i];

      if(isInside(nx,ny)){
        if((miro[nx][ny] == '.' || miro[nx][ny] == 'D') && !visited[nx][ny]){
          if(waterMap[nx][ny] > dist + 1){
            visited[nx][ny] = true; 
            Q.push({{nx,ny}, dist+1});
          }
        }
      }
    }
  }
  return -1;
}

void sol(){
  getInput();
  waterBFS();
  int result = bfs(S.first, S.second);
  if(result == -1)cout<<"KAKTUS";
  else cout<<result;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  sol();
}