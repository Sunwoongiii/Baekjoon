#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int n,m,k;
bool visited[110][110] = {false};
int miro[110][110] = {0};
queue<pair<int,int>>q;
int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};
vector<int>v;

bool isInside(int a, int b){
  return (a>=1 && a <= n && b >= 1 && b <= m);
}

void getInput(){
  cin>>m>>n>>k;
  for(int i = 0; i < k; i++){
    int a,b;
    cin>>a>>b;
    miro[a][b] = 1;
  }
}

int bfs(int a, int b){
  int size = 0;
  q.push({a,b});
  while(!q.empty()){
    int x = q.front().first;
    int y = q.front().second;
    if(visited[x][y])continue;
    visited[x][y] = true;
    q.pop();
    size++;

    for(int i = 0; i < 4; i++){
      int nx = x + dx[i];
      int ny = y + dy[i];

      if(isInside(nx,ny) && !visited[nx][ny] && miro[nx][ny] == 1){
        q.push({nx,ny});
      }
    }
  }
  return size;
}

int solve(){
  getInput();
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      if(!visited[i][j] && miro[i][j] == 1)v.push_back(bfs(i,j));
    }
  }

  return *max_element(v.begin(), v.end());
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cout<<solve();
}