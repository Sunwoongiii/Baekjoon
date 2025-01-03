#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int m,n,k;
queue<pair<int,int>>q;
int dx[4] = {0,0,-1,1}, dy[4] = {-1,1,0,0};
bool visited[101][101];
vector<int> area;


void bfs(int a, int b){
  q.push({a,b});
  visited[a][b] = true;
  int cnt = 0;
  
  while(!q.empty()){
    int y = q.front().first;
    int x = q.front().second;
    q.pop();
    cnt++;

    for(int i = 0; i < 4; i++){
      int nx = x + dx[i];
      int ny = y + dy[i];

      if(nx < n && nx >= 0 && ny < m && ny >= 0){
        if(!visited[ny][nx]){
          q.push({ny, nx});
          visited[ny][nx] = true;
        }
      }
    }
  }
  area.push_back(cnt);
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int ans = 0;
  cin>>m>>n>>k;
  for(int i = 0; i < k; i++){
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    for(int r = b; r < d; r++){
      for(int l = a; l < c; l++){
        visited[r][l] = true;
      }
    }
  }
  for(int i = 0; i < m; i++){
    for(int j = 0; j < n; j++){
      if(!visited[i][j]){
        bfs(i,j);
        ans++;
      }
    }
  }
  cout<<ans<<"\n";
  sort(area.begin(), area.end());
  for(int i = 0; i < area.size(); i++){
    cout<<area[i]<<" ";
  }
  return 0;
}