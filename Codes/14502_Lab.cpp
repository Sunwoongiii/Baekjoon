#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n,m,zero,virus,wall;
int miro[10][10];
int dx[4] = {0,0,-1,1};
int dy[4] = {1,-1,0,0};
bool visited[10][10];
queue<pair<int,int>>q;
vector<int>safeRegion;

bool isInside(int x, int y){
  return (x >= 0 && y >= 0 && x < n && y < m);
}

void reset(){
  virus = 0;
  while(!q.empty()) q.pop();

  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      visited[i][j] = false;
      if(miro[i][j] == 2){
        virus++;
        q.push({i,j});
        visited[i][j] = true;
      }
    }
  }
}

int bfs(){
  reset();

  while(!q.empty()){
    int x = q.front().first;
    int y = q.front().second;
    q.pop();

    for(int i = 0; i < 4; i++){
      int nx = x + dx[i];
      int ny = y + dy[i];

      if(isInside(nx, ny) && !visited[nx][ny] && miro[nx][ny] == 0){
        q.push({nx, ny});
        visited[nx][ny] = true;
        virus++;
      }
    }
  }
  return (n*m - (virus+ wall + 3));
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin>>n>>m;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      cin>>miro[i][j];
      if(miro[i][j] == 0) zero++;
      if(miro[i][j] == 1) wall++;
    }
  }

  int total = n*m;
  for(int i = 0; i < total-2; i++){
    if(miro[i/m][i%m] != 0) continue;

    for(int j = i + 1; j < total-1; j++){
      if(miro[j/m][j%m] != 0) continue;

      for(int k = j + 1; k < total; k++){
        if(miro[k/m][k%m] != 0) continue;

        miro[i/m][i%m] = 1;
        miro[j/m][j%m] = 1;
        miro[k/m][k%m] = 1;

        safeRegion.push_back(bfs());

        miro[i/m][i%m] = 0;
        miro[j/m][j%m] = 0;
        miro[k/m][k%m] = 0;
      }
    }
  }

  cout<<*max_element(safeRegion.begin(), safeRegion.end());
  return 0;
}