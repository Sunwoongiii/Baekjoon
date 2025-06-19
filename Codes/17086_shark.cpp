#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int n,m;
int miro[55][55];
int ans[55][55];
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
int dx[8] = {0, 0, 1, 1, 1, -1, -1, -1};
int dy[8] = {1, -1, 1, -1, 0, 0, -1, 1};

void getInput(){
  cin>>n>>m;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      cin>>miro[i][j];
      ans[i][j] = 1e9;
      if(miro[i][j] == 1){
        ans[i][j] = 0;
        pq.push({i,j});
      }
    }
  }
}

bool isInside(int a, int b){
  return(a>=0&&b>=0&&a<n&&b<m);
}

int dijkstra(){
  while(!pq.empty()){
    int x = pq.top().first;
    int y = pq.top().second;
    pq.pop();

    for(int i = 0; i < 8; i++){
      int nx = x + dx[i];
      int ny = y + dy[i];

      if(isInside(nx,ny) && ans[nx][ny] > ans[x][y] + 1 && miro[nx][ny] == 0){
        ans[nx][ny] = ans[x][y] + 1;
        pq.push({nx,ny});
      }
    }
  }

  int max = -1;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      if(max < ans[i][j]) max = ans[i][j];
    }
  }
  return max;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  getInput();
  cout<<dijkstra();
}