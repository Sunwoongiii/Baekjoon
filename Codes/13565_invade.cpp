#include <iostream>
#include <queue>
using namespace std;

int n,m;
char miro[1010][1010];
bool visited[1010][1010];
queue<pair<int,int>>q;
int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};

void getInput(){
  cin>>n>>m;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      cin>>miro[i][j];

      if(miro[i][j] == '0' && i == 0){
        q.push({i,j});
        visited[i][j] = true;
      }
    }
  }
}

bool isInside(int a, int b){
  return(a>=0&&b>=0&&a<n&&b<m);
}

string bfs(){
  while(!q.empty()){
    int x = q.front().first;
    int y = q.front().second;
    q.pop();

    if(x == n-1)return "YES";

    for(int i = 0; i < 4; i++){
      int nx = x + dx[i];
      int ny = y + dy[i];

      if(isInside(nx,ny) && !visited[nx][ny] && miro[nx][ny] == '0'){
        q.push({nx,ny});
        visited[nx][ny] = true;
      }
    }
  }
  return "NO";
}

void sol(){
  getInput();
  cout<<bfs();
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  sol();
}