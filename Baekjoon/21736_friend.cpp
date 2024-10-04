#include <iostream>
#include <queue>
using namespace std;

int n,m,fir = 0;
char miro[606][606];
bool visited[606][606];
int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};
queue<pair<int,int>>q;

bool isInside(int a,int b){
  return(a>=0&&b>=0&&a<n&&b<m);
}

void getInput(){
  cin>>n>>m;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      cin>>miro[i][j];
      if(miro[i][j] == 'I'){
        q.push({i,j});
        visited[i][j] = true;
        miro[i][j] = 'O';
      }
    }
  }
}

int bfs(){
  while(!q.empty()){
    int x = q.front().first;
    int y = q.front().second;
    q.pop();

    for(int i = 0; i < 4; i++){
      int nx = x + dx[i];
      int ny = y + dy[i];

      if(isInside(nx,ny) && !visited[nx][ny] && miro[nx][ny] != 'X'){
        visited[nx][ny] = true;
        q.push({nx,ny});
        if(miro[nx][ny] == 'P') fir++;
      }
    }
  }
  return fir;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  getInput();
  int result = bfs();

  if(result == 0){
    cout<<"TT\n";
  }
  else cout<<result<<"\n";
  return 0;
}