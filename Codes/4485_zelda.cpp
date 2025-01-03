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

int miro[130][130];
int ans[130][130];
bool visited[130][130];
priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>>>pq;
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
int n;

void reset(){
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      visited[i][j] = false;
      ans[i][j] = 2e9;
    }
  }
  while(!pq.empty()) pq.pop();
}

bool isInside(int p, int q){
  return(p >= 0 && q >= 0 && p < n && q < n);
}

int dijkstra(){
  ans[0][0] = miro[0][0];
  pq.push({miro[0][0],0,0});
  while(!pq.empty()){
    int value,x,y;
    tie(value, x, y) = pq.top();
    pq.pop();

    if(visited[x][y]||!isInside(x,y)) continue;
    visited[x][y] = true;
    if(x==n-1 && y==n-1) return ans[x][y];

    for(int i = 0; i < 4; i++){
      int nx = x + dx[i];
      int ny = y + dy[i];
      int cost = miro[nx][ny];

      if(visited[nx][ny]|| !isInside(nx,ny)) continue;
      if(ans[nx][ny] > ans[x][y] + cost){
        ans[nx][ny] = ans[x][y] + cost;
        pq.push({ans[nx][ny], nx,ny});
      }
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int testCase = 1;
  while(true){
    cin>>n;
    if(n == 0) break;
    else{
      for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
          cin>>miro[i][j];
        }
      }
      reset();
      int result = dijkstra();
      cout<<"Problem "<<testCase<<": "<<result<<"\n";
      testCase++;
    }
  }
  return 0;
}