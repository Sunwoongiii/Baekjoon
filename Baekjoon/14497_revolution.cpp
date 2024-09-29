#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n,m;
char miro[303][303];
int jump[303][303];
int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};
int jx,jy,targetX,targetY;
queue<pair<int,int>>q;
bool visited[303][303];

bool isInside(int a, int b){
  return (a >= 0 && b >= 0 && a < n && b < m);
}

void getInput(){
  cin>>n>>m>>jy>>jx>>targetY>>targetX;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      cin>>miro[i][j];
    }
  }
}

int bfs(){
  q.push({jx,jy});
  visited[jx][jy] = true;

  while(!q.empty()){
    int x = q.front().first;
    int y = q.front().second;
    q.pop();

    for(int i = 0; i < 4; i ++){
      int nx = x + dx[i];
      int ny = y + dy[i];


    }
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  getInput();
}