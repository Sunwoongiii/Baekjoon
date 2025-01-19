#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int T,n,m;
pair<int,int> start;
char miro[1010][1010];
bool visited[1010][1010];
int fireMap[1010][1010];
int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};
queue<pair<int,int>>q;

void reset(int a, int b){
  for(int i = 0; i < a; i++){
    for(int j = 0; j < b; j++){
      visited[i][j] = false;
      fireMap[i][j] = 1e9;
    }
  }
  while(!q.empty())q.pop();
}

bool isInside(int a, int b){
  return(a>=0&&b>=0&&a<n&&b<m);
}

void fireBfs(){
  while(!q.empty()){
    int x = q.front().first;
    int y = q.front().second;
    q.pop();

    for(int i = 0; i < 4; i++){
      int nx = x + dx[i];
      int ny = y + dy[i];

      if(isInside(nx,ny) && miro[nx][ny] != '#' && fireMap[nx][ny] > fireMap[x][y] + 1){
        fireMap[nx][ny] = fireMap[x][y] + 1;
        q.push({nx,ny});
      }
    }
  }
}

int personBfs(int a, int b){
  queue<pair<pair<int,int>,int>>Q;
  Q.push({{a,b},0});
  visited[a][b] = true;

  while(!Q.empty()){
    int x = Q.front().first.first;
    int y = Q.front().first.second;
    int dist = Q.front().second;
    Q.pop();

    if(x == 0 || y == 0 || x == n-1 || y == m-1)return dist+1;

    for(int i = 0; i < 4; i++){
      int nx = x + dx[i];
      int ny = y + dy[i];

      if(isInside(nx,ny) && miro[nx][ny] != '#' && !visited[nx][ny] && fireMap[nx][ny] > dist + 1){
        visited[nx][ny] = true;
        Q.push({{nx,ny},dist+1});
      }
    }
  }
  return -1;
}

void Sol(){
  cin>>T;

  while(T--){
    cin>>m>>n;
    reset(n,m);
    for(int i = 0; i < n; i++){
      for(int j = 0; j < m; j++){
        cin>>miro[i][j];

        if(miro[i][j] == '@'){
          start.first = i;
          start.second = j;
        }
        else if(miro[i][j] == '*'){
          q.push({i,j});
          fireMap[i][j] = 0;
        }
      }
    }

    fireBfs();
    int result = personBfs(start.first, start.second);
    if(result == -1) cout<<"IMPOSSIBLE\n";
    else cout<<result<<'\n';
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  Sol();
}