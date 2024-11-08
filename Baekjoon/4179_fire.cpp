#include <iostream>
#include <queue>
using namespace std;

int r,c;
char miro[1010][1010];
int fireMap[1010][1010];
bool visited[1010][1010];
pair<int,int> Start, Fire;
int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};
queue<pair<int,int>>q;

void input(){
  cin>>r>>c;
  for(int i = 0; i < r;i++){
    for(int j=0;j<c;j++){
      cin>>miro[i][j];
      bool fire = false;
      if(miro[i][j] == 'J'){
        Start.first = i;
        Start.second = j;
      }
      else if(miro[i][j] == 'F'){
        q.push({i,j});
        fireMap[i][j] = 0;
        fire = true;
      }
      if(fire == false) fireMap[i][j] = 2e9;
    }
  }
}

void fireBfs(int a, int b){
  while(!q.empty()){
    int qS = q.size();
    for(int s = 0; s < qS; s++){
      int x = q.front().first;
      int y = q.front().second;
      q.pop();

      for(int i = 0; i < 4;i++){
        int nx=x+dx[i];
        int ny=y+dy[i];

        if(nx>=0&&ny>=0&&nx<r&&ny<c){
          if(miro[nx][ny] != '#'){
            if(fireMap[nx][ny] > fireMap[x][y] +1){
              fireMap[nx][ny] = fireMap[x][y]+1;
              q.push({nx,ny});
            }
          }
        }
      }
    }
  }
}

int personBfs(int a, int b){
  queue<pair<pair<int,int>,int>>Q;
  Q.push({{a,b},0});
  visited[a][b]=true;

  while(!Q.empty()){
    int x = Q.front().first.first;
    int y = Q.front().first.second;
    int cnt = Q.front().second;
    Q.pop();

    if(x==0||y==0||x==r-1||y==c-1)return cnt+1;
    
    for(int i =0;i<4;i++){
      int nx=x+dx[i];
      int ny=y+dy[i];

      if(nx>=0&&ny>=0&&nx<r&&ny<c){
        if(miro[nx][ny] != '#' && !visited[nx][ny]){
          if(fireMap[nx][ny] > cnt+1){{
            visited[nx][ny] = true;
            Q.push({{nx,ny},cnt+1});
          }}
        }
      }
    }
  }
  return -1;
}

void solution(){
  fireBfs(Fire.first, Fire.second);
  int result = personBfs(Start.first, Start.second);
  if(result == -1)cout<<"IMPOSSIBLE";
  else cout<<result<<"\n";
}

void Solve(){
  input();
  solution();
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  Solve();
  return 0;
}