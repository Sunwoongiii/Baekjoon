#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <math.h>

using namespace std;
int t,l, targetX, targetY, initialX, initialY;
int minMove = 0;
int dy[8] = {-2, -1, +1, +2, +2, +1, -1, -2};
int dx[8] = {+1, +2, +2, +1, -1, -2, -2, -1};
bool chess[303][303] = {false};
queue<pair<pair<int,int>,int>>q;


void reset(){
  for(int i = 0; i < l; i++){
    for(int j = 0; j < l; j++){
      chess[i][j] = false;
    }
  }
  minMove = -1;
  while(!q.empty()) q.pop();
}

bool isInside(int a, int b, int l){
  return (a >= 0 && b >= 0 && a < l && b < l);
}

void bfs(int a, int b){
  while (!q.empty())
  {
    pair<pair<int, int>,int> element = q.front();
    int x = element.first.first;
    int y = element.first.second;
    int move = element.second;
    q.pop();
    
    for(int i = 0; i < 8; i++){
      int nx = x + dx[i];
      int ny = y + dy[i];

      if(nx == targetX && ny == targetY){
        minMove = move+1;
        return;
      }

      if(isInside(nx, ny, l) == 1 && !chess[nx][ny]){
        chess[nx][ny] =true;
        q.push(make_pair(make_pair(nx,ny), move+1));
      }
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin>>t;
  while(t--){
    reset();
    cin>>l>>initialX>>initialY>>targetX>>targetY;

    if(initialX == targetX && initialY == targetY){
      minMove = 0;
    }

    else{
      q.push(make_pair(make_pair(initialX, initialY), 0));
      chess[initialX][initialY] = true;
      bfs(initialX, initialY);
    }
  cout<<minMove<<"\n";
  }

  return 0;
}