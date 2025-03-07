#include <iostream>
#include <queue>
using namespace std;

int n,m,x_1,x_2,y_1,y_2,res;
char miro[303][303];
bool visited[303][303], flag;
queue<pair<int,int>>q;
int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};

void getInput(){
  cin>>n>>m>>x_1>>y_1>>x_2>>y_2;
  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= m; j++){
      cin>>miro[i][j];
    }
  }
  q.push({x_1,y_1});
  visited[x_1][y_1] = true;
}

bool isInside(int a, int b){
  return(a>=0&&b>=0&&a<n&&b<m);
}

void bfs(){
  while(!q.empty()){
    int x = q.front().first;
    int y = q.front().second;
    q.pop();

    for(int i = 0; i < 4; i++){
      int nx = x + dx[i];
      int ny = y + dy[i];

      if(isInside(nx,ny) && miro[nx][ny] == '#'){
        flag =true;
        return;
      }

      if(isInside(nx,ny) && !visited[nx][ny]){
        visited[nx][ny] = true;
        if(miro[nx][ny] == '1')miro[nx][ny] = '0';
        else if(miro[nx][ny] == '0')q.push({nx,ny});
      }
    }
  }
}

void sol(){
  getInput();
  
  while(true){
    res++;
    bfs();
    if(flag)break;
  }
  cout<<res;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  sol();
}