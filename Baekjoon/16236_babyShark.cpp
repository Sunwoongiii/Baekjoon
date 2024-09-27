#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <utility>
using namespace std;

int n,curX,curY,board[22][22],visited[22][22],ans,Size=2,ate;
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};

bool isInside(int a, int b){
  return(a >= 0 && b >= 0 && a < n && b < n);
}

int bfs(){
  for(int i = 0; i < n; i++)fill(visited[i], visited[i]+n, 0);

  queue<pair<int,int>>q;
  priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>>>pq;
  q.push({curX, curY});
  visited[curX][curY] = 1;

  while(!q.empty()){
    int x = q.front().first;
    int y = q.front().second;
    q.pop();

    for(int i = 0; i < 4; i++){
      int nx = x + dx[i];
      int ny = y + dy[i];

      if(!isInside(nx,ny))continue;
      if(visited[nx][ny]) continue;
      if(board[nx][ny] > Size) continue;

      visited[nx][ny] = visited[x][y] + 1;
      if(board[nx][ny] > 0 && board[nx][ny] < Size) pq.push({visited[nx][ny],nx,ny});
      else q.push({nx,ny});
    }
  }
  if(pq.empty()) return 0;
  int dist = get<0>(pq.top());
  int fish_x = get<1>(pq.top());
  int fish_y = get<2>(pq.top());

  curX = fish_x;
  curY = fish_y;

  board[curX][curY] = 0;
  ate++;

  if(ate == Size){
    Size++;
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
        curX = i;
        curY = j;
        board[i][j] = 0;
      }
    }
  }
  while(true){
    int sec = bfs();
    if(sec == 0)break;
    ans+=sec;
  }
  cout<<ans<<"\n";
}