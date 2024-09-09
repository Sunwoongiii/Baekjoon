#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <tuple>

using namespace std;

int n;
char miro[55][55];
bool visited[55][55];
priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>>>pq;
int dx[4] = {0,0,-1,1};
int dy[4] = {1,-1,0,0};

bool isInside(int a, int b){
  return (a>= 0 && b >= 0 && a < n && b < n);
}

int dijkstra(){
  pq.push({0,0,0});
  visited[0][0] = true;

  while(!pq.empty()){
    int value, x, y;
    tie(value, x, y) = pq.top();
    pq.pop();

    if(x == n-1 && y == n-1) return value;

    for(int i = 0; i < 4; i++){
      int nx = x + dx[i];
      int ny = y + dy[i];

      if(isInside(nx,ny) && !visited[nx][ny]){
        visited[nx][ny] = true;
        if(miro[nx][ny] == '1') pq.push({value, nx, ny});
        else if(miro[nx][ny] == '0') pq.push({value+1, nx, ny});
      }
    }
  }
  return -1;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin>>n;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      cin>>miro[i][j];
    }
  }
  cout<<dijkstra();
}