#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n,m;//n:세로 m:가로
char miro[101][101];
int ans[101][101][4];//x,y,방향
bool visited[101][101][4];//x,y,방향
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
int sx,sy,ex,ey;

class State{
public:
  int x,y,dir,changed;
};

void getInput(){
  cin>>m>>n;
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      cin>>miro[i][j];
      if(miro[i][j]=='C'){
        if(sx==0&&sy==0){
          sx=i;
          sy=j;
        }else{
          ex=i;
          ey=j;
        }
      }
      for(int k=0;k<4;k++){
        ans[i][j][k]=1e9;
      }
    }
  }
}

bool isInside(int x,int y){
  return x>=0&&x<n&&y>=0&&y<m;
}

int bfs(){
  queue<State> q;
  for(int i=0;i<4;i++){
    ans[sx][sy][i]=0;
    visited[sx][sy][i]=true;
    q.push({sx,sy,i,0});
  }

  while(!q.empty()){
    State cur=q.front();
    q.pop();
    int x=cur.x;
    int y=cur.y;
    int dir=cur.dir;
    int changed=cur.changed;

    for(int d = 0; d < 4; d++){
      int nx = x + dx[d];
      int ny = y + dy[d];
      int nextChange = changed + (dir != d);

      if(isInside(nx,ny) && miro[nx][ny] != '*' &&(!visited[nx][ny][d] || ans[nx][ny][d] > nextChange)){
        visited[nx][ny][d] = true;
        ans[nx][ny][d] = nextChange;

        if(dir == d){
          q.push({nx,ny,d,changed});
        }
        else{
          q.push({nx,ny,d,nextChange});
        }
      }
    }
  }
  int result = 1e9;
  for(int i = 0; i < 4; i++){
    result = min(result, ans[ex][ey][i]);
  }
  return result;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  getInput();
  cout<<bfs()<<'\n';

  // for(int i = 0; i < n; i++){
  //   for(int j = 0; j < m; j++){
  //     cout<<miro[i][j]<<' ';
  //   }
  //   cout<<"\n\n";
  // }

  // for(int k = 0; k < 4; k++){
  //   for(int i = 0; i < n; i++){
  //     for(int j = 0; j < m; j++){
  //       if(ans[i][j][k] == 1e9)cout<<"* ";
  //       else cout<<ans[i][j][k]<<' ';
  //     }
  //     cout<<"\n";
  //   }
  //   cout<<"\n\n";
  // }
}