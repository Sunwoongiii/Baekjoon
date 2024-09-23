#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility>
#include <tuple>

using namespace std;

int board[22][22];
int visited[22][22];
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};
int ans, curx,cury,n,ate,size = 2;

int bfs(){
  for(int i = 0; i < n; i++){
    fill(visited[i], visited[i] + n, 0);
  }

  queue<pair<int,int>>q;
  priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>>>pq;
  q.push({curx, cury});
  visited[curx][cury] = 1;

  while(!q.empty()){
    int x = q.front().first;
    int y = q.front().second;
    q.pop();

    for(int i = 0; i < 4; i++){
      int nx = x + dx[i];
      int ny = y + dy[i];

      if(ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
      if(visited[nx][ny]) continue;
      if(board[nx][ny] == 0 || board[nx][ny] == size){
        visited[nx][ny] = visited[x][y] + 1;
        q.push({nx,ny});
      }
      else if(board[nx][ny] < size){
        visited[nx][ny] = visited[x][y] + 1;
        pq.push({visited[nx][ny],nx,ny});
      }
    }
  }

  if(pq.empty()) return 0;
  int dist = get<0>(pq.top());
  int fish_x = get<1>(pq.top());
  int fish_y = get<2>(pq.top());

  curx = fish_x;
  cury = fish_y;
  board[curx][cury] = 0;
  ate++;
  if(ate == size){
    size++;
    ate = 0;
  }
  return dist-1;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin>>n;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      cin>>board[i][j];
      if(board[i][j] == 9){
        curx = i;
        cury = j;
        board[i][j] = 0;
      }
    }
  }

  while(true){
    int sec = bfs();
    if(sec == 0) break;
    ans+=sec;
  }
  cout<<ans<<"\n";
}