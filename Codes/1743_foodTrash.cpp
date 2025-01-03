#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n,m,k;
vector<pair<int,int>>v;
bool miro[110][110];
bool visited[110][110];
int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};
int result = 0;

bool isInside(int a, int b){
  return(a>=1&&b>=1&&a<=n&&b<=m);
}

void bfs(int a, int b){
  queue<pair<int,int>>q;
  int cnt = 1;
  visited[a][b] = true;
  q.push({a,b});

  while(!q.empty()){
    int x = q.front().first;
    int y = q.front().second;
    q.pop();

    for(int i = 0; i < 4; i++){
      int nx = x + dx[i];
      int ny = y + dy[i];

      if(isInside(nx,ny) && miro[nx][ny] && !visited[nx][ny]){
        q.push({nx,ny});
        visited[nx][ny] = true;
        cnt++;
      }
    }
  }
  result = max(result, cnt);
}

void getInput(){
  cin>>n>>m>>k;
  int a,b;
  for(int i = 0; i < k; i++){
    cin>>a>>b;
    v.push_back({a,b});
    miro[a][b] = true;
  }
}

void sol(){
  getInput();
  for(int i = 0; i < k; i++){
    bfs(v[i].first, v[i].second);
  }
  cout<<result;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  sol();
}