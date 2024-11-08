#include <iostream>
#include <deque>
#include <vector>
#include <climits>
using namespace std;

int n,m,startX,startY,endX,endY;
char miro[110][110];
int ans[110][110];
bool visited[110][110][4];
int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};

class State{
public:
  int x,y,dir,changed;
};

void getInput(){
  cin>>n>>m;\
  int cnt = 0;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      cin>>miro[i][j];
      if(miro[i][j] == 'C' && cnt == 0){
        startX = i;
        startY = j;
        cnt++;
      }
      if(miro[i][j] == 'C' && cnt == 1){
        endX = i;
        endY = j;
      }
      ans[i][j] = 1e9;
    }
  }
}

bool isInside(int a, int b){
  return(a>=0&&b>=0&&a<n&&b<m);
}

int bfs(){
  deque<State>dq;

  for(int i = 0; i < 4; i++){
    dq.push_back({startX, startY, i, 0});
    visited[startX][startY][i] = true;
    ans[startX][startY] = 0;
  }

  while(!dq.empty()){
    State cur =dq.front();
    dq.pop_front();

    for(int d = 0; d < 4; d++){
      int nx = cur.x + dx[d];
      int ny = cur.y + dy[d];
      int nextChange = cur.changed + (cur.dir != d);

      if(isInside(nx,ny) && miro[nx][ny] != '*' && (!visited[nx][ny][d] || ans[nx][ny] > nextChange)){
        visited[nx][ny][d] = true;
        ans[nx][ny] = nextChange;

        if(cur.dir == d) dq.push_front({nx,ny,d,cur.changed});
        else dq.push_back({nx,ny,d,nextChange});
      }
    }
  }
  return ans[endX][endY] == 1e9 ? -1 : ans[endX][endY];
}

void solve(){
  getInput();
  cout<<bfs();
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  solve();
  return 0;
}