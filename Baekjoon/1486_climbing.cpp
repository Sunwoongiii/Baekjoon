#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <math.h>
#include <tuple>
using namespace std;

int n,m,t,d;
int miro[30][30];
bool visited[30][30];
int ans[30][30];
priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>>>pq;
int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};

void getInput(){
  cin>>n>>m>>t>>d;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      ans[i][j] = 1e9;
      char temp;
      cin>>temp;
      if(islower(temp)) miro[i][j] = temp-71;
      else miro[i][j] = temp-65;
    }
  }
}

bool isInside(int a, int b){
  return(a>=0&&b>=0&&a<n&&b<m);
}

void dijkstra(){
  pq.push({0,0,0});
  ans[0][0] = 0;
  
  while(!pq.empty()){
    int time, x, y;
    tie(time, x, y) = pq.top();
    pq.pop();

    if(visited[x][y])continue;
    visited[x][y] = true;

    for(int i = 0; i < 4; i++){
      int nx = x + dx[i];
      int ny = y + dy[i];

      if(isInside(nx,ny) && !visited[nx][ny]){
        int temp = abs(miro[nx][ny] - miro[x][y]);
        
        if(temp <= t && miro[nx][ny] <= miro[x][y] && ans[nx][ny] > ans[x][y] + 1){
          ans[nx][ny] = ans[x][y] + 1;
          pq.push({ans[nx][ny], nx, ny});
        }

        else if(temp <= t && miro[nx][ny] > miro[x][y] && ans[nx][ny] > ans[x][y] + temp*temp){
          ans[nx][ny] = ans[x][y] + temp*temp;
          pq.push({ans[nx][ny], nx, ny});;
        }
      }
    }
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  getInput();
  dijkstra();
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      cout<<miro[i][j]<<' ';
    }
    cout<<'\n';
  }

  cout<<'\n';
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      cout<<ans[i][j]<<' ';
    }
    cout<<'\n';
  }
}