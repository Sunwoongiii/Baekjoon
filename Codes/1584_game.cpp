#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int N,M,life;//N: 위험(1), M: 죽음(2)
int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};
int area[505][505];
int ans[505][505];

void getInput(){
  cin>>N;
  for(int i = 0; i < N; i++){
    int x1,y1,x2,y2;
    cin>>x1>>y1>>x2>>y2;

    for(int j = min(x1,x2); j <= max(x1,x2); j++){
      for(int k = min(y1,y2); k <= max(y1,y2); k++){
        area[j][k] = 1;
      }
    }
  }

  cin>>M;
  for(int i = 0; i < M; i++){
    int x1,y1,x2,y2;
    cin>>x1>>y1>>x2>>y2;

    for(int j = min(x1,x2); j <= max(x1,x2); j++){
      for(int k = min(y1,y2); k <= max(y1,y2); k++){
        area[j][k] = 2;
      }
    }
  }
  area[0][0] = 0;
}

bool isInside(int a, int b){
  return (a>=0&&b>=0&&a<=500&&b<=500);
}

int bfs(){
  memset(ans, -1, sizeof(ans));
  priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<>>pq;
  pq.push({0,{0,0}});
  ans[0][0] = 0;

  while(!pq.empty()){
    int cost = pq.top().first;
    int x = pq.top().second.first;
    int y = pq.top().second.second;
    pq.pop();

    if(x == 500 && y == 500)return ans[500][500];

    for(int i = 0; i < 4; i++){
      int nx = x + dx[i];
      int ny = y + dy[i];

      if(isInside(nx,ny) && area[nx][ny] != 2){
        int new_cost = cost + (area[nx][ny] == 1 ? 1:0);

        if(ans[nx][ny] == -1 || new_cost < ans[nx][ny]){
          ans[nx][ny] = new_cost;
          pq.push({new_cost,{nx,ny}});
        }
      }
    }
  }
  return -1;
}

void sol(){
  getInput();
  cout<<bfs();
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  sol();
  return 0;
}