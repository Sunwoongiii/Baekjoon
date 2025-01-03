#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

class Virus{
  public:
    int x;
    int y;
};

Virus virus[11];
int n,m;
int miro[55][55],ans[55][55];
queue<pair<int,int>>q;
int dx[4] = {0,0,-1,1};
int dy[4] = {1,-1,0,0};
bool visited[55][55];

void getInput(){
  cin>>n>>m;
  int virusCnt = 0;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      cin>>miro[i][j];
      ans[i][j] = miro[i][j];
      if(miro[i][j] == 2){
        virus[virusCnt].x = i;
        virus[virusCnt].y = j;
        virusCnt++;
      }
    }
  }
}

void reset(){
  for(int i = 0; i < n; i++){
    fill(visited[i], visited[i]+n, false);
  }
}

bool isInside(int a, int b){
  return (a>=0&&b>=0&&a<n&&b<n);
}

int bfs(){
  while(!q.empty()){
    int x = q.front().first;
    int y = q.front().second;
    q.pop();

    for(int i = 0; i < n; i++){
      int nx = x + dx[i];
      int ny = y + dy[i];

      if(isInside(nx,ny) && !visited[nx][ny] && miro[nx][ny] != 1){
        visited[nx][ny] = true;
        if(miro[nx][ny] == 0){
          miro[nx][ny] = miro[x][y] + 1;
          
        }
      }
    }
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  getInput();
}