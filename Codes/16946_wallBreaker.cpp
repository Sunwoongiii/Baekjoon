#include <iostream>
#include <queue>
#include <set>
using namespace std;

int n,m;
char miro[1010][1010];
int area[1010][1010];
int areaSize[1001000];
int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};

bool isInside(int a, int b){
  return(a>=0&&b>=0&&a<n&&b<m);
}

void bfs(){
  int areaNum = 1;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      if(miro[i][j] == '0' && area[i][j] == 0){
        queue<pair<int,int>>q;
        q.push({i,j});
        area[i][j] = areaNum;
        int cnt = 1;

        while(!q.empty()){
          int x = q.front().first;
          int y = q.front().second;
          q.pop();

          for(int d = 0; d < 4; d++){
            int nx = x + dx[d];
            int ny = y + dy[d];

            if(isInside(nx,ny) && miro[nx][ny] == '0' && area[nx][ny] == 0){
              area[nx][ny] = areaNum;
              ++cnt;
              q.push({nx,ny});
            }
          }
        }
        areaSize[areaNum++] = cnt;
      }
    }
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin>>n>>m;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      cin>>miro[i][j];
    }
  }

  bfs();

  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      if(miro[i][j] == '1'){
        set<int>neighbor;

        for(int d = 0; d < 4; d++){
          int ni = i + dx[d];
          int nj = j + dy[d];

          if(isInside(ni,nj) && area[ni][nj]>0){
            neighbor.insert(area[ni][nj]);
          }
        }
        int sum = 1;
        for(int idx : neighbor) sum += areaSize[idx];
        cout<<sum%10;
      }
      else cout<<0;
    }
    cout<<'\n';
  }
}