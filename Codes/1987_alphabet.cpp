#include <iostream>
#include <algorithm>
using namespace std;

int R,C,ans;
int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};
char miro[22][22];
bool visited[26];

void getInput(){
  cin>>R>>C;
  for(int i = 0; i < R; i++)
    for(int j = 0; j < C; j++)
      cin>>miro[i][j];
}

bool isInside(int a, int b){
  return(a>=0&&b>=0&&a<R&&b<C);
}

void dfs(int x, int y, int cnt){
  ans = max(ans, cnt);

  for(int i = 0; i < 4; i++){
    int nx = x + dx[i];
    int ny = y + dy[i];

    if(isInside(nx,ny)){
      if(visited[miro[nx][ny] - 'A'] == false){
        visited[miro[nx][ny] - 'A'] = true;
        dfs(nx,ny,cnt+1);
        visited[miro[nx][ny] - 'A'] = false;
      }
    }
  }
}

void sol(){
  getInput();
  visited[miro[0][0] - 'A'] = true;
  dfs(0,0,1);

  cout<<ans;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  sol();
}