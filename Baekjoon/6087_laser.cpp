#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;

int n,m;
char MAP[101][101];
int Mirror[101][101][4];
int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};
int startX,startY,endX,endY;

void init(){
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      for(int k = 0; k < 4; k++){
        Mirror[i][j][k] = 1e9;
      }
    }
  }
}

void getInput(){
  cin>>n>>m;
  int cnt = 0;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      cin>>MAP[i][j];
      if(MAP[i][j] == 'C' && cnt == 0){
        cnt++;
        startX=i;
        startY=j;
      }
      else if(MAP[i][j] == 'C' && cnt == 1){
        endX=i;
        endY=j;
      }
    }
  }
}

bool isInside(int a, int b){
  return(a>=0&&b>=0&&a<n&&b<m);
}

int bfs(){
  deque<pair<int,pair<int,int>>>dq;

  for(int i = 0; i < 4; i++){
    dq.push_back({0,{startX,startY}});
    Mirror[startX][startY][i] = 0;
  }

  while(!dq.empty()){
    auto[curMirrors, pos] = dq.front();
    int x = pos.first;
    int y = pos.second;
    dq.pop_front();

    for(int i = 0; i < 4; i++){
      int nx = x + dx[i];
      int ny = y + dy[i];
      int nextMirror = curMirrors + (Mirror[x][y][i] != i);

      if(isInside(nx,ny) && MAP[nx][ny] != '*'){
        if(Mirror[nx][ny][i] > nextMirror){
          Mirror[nx][ny][i] = nextMirror;

          if(Mirror[x][y][i] == i){
            dq.push_front({nextMirror,{nx,ny}});
          }
          else{
            dq.push_back({nextMirror, {nx,ny}});
          }
        }
      }
    }
  }

  int ans = 1e9;
  for(int i = 0; i < 4; i++){
    ans = min(ans, Mirror[endX][endY][i]);
  }
  return ans;
}

void sol(){
  init();
  getInput();
  cout<<bfs()<<'\n';
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  sol();
  return 0;
}