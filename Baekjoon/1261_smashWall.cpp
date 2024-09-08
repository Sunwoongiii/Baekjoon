#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <math.h>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <sstream>

using namespace std;
using ll = long long;

int m,n;
char miro[101][101];
bool visited[101][101];
priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
//value, x, y순서
int dx[4] = {0,0,-1,1};
int dy[4] = {1,-1,0,0};

bool isInside(int x, int y){
  return (x >= 1 && y >= 1 && x <= n && y <= m);
}

int dijkstra(){
  pq.push({0,1,1});
  visited[1][1] = true;

  while(!pq.empty()){
    int value, x, y;
    tie(value, x, y) = pq.top();
    pq.pop();
    if(x == n && y == m) return value;

    for(int i = 0; i < 4; i++){
      int nx = x + dx[i];
      int ny = y + dy[i];

      if(isInside(nx,ny) && !visited[nx][ny]){
        visited[nx][ny] = true;
        if(miro[nx][ny] == '0'){
          pq.push({value, nx, ny});
        }
        else if(miro[nx][ny] == '1'){
          pq.push({value+1,nx,ny});
        }
      }
    }
  }
  return -1;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin>>m>>n;
  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= m; j++){
      cin>>miro[i][j];
    }
  }
  cout<<dijkstra();

}