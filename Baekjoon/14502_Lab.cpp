#include <queue>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
using ll = long long;

int n, m;
int zero = 0;
int infected = 0;
int miro[10][10];
int postMiro[10][10];
bool visited[10][10];
queue<pair<int,int>>q;
vector<int> safeRegion;
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

bool isInside(int a, int b){
  return (a >= 0 && b >= 0 && a < n && b < m);
}

void reset(){
  while(!q.empty()) q.pop();
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      visited[i][j] = false;
      postMiro[i][j] = miro[i][j];
      if(miro[i][j] == 2) q.push({i,j});
    }
  }
}

int bfs(){
  reset();
  infected = 0;

  while(!q.empty()){
    int x = q.front().first;
    int y = q.front().second;
    visited[x][y] = true;
    q.pop();

    for(int i = 0; i < 4; i++){
      int nx = x + dx[i];
      int ny = y + dy[i];

      if(isInside(nx, ny) && !visited[nx][ny] && postMiro[nx][ny] == 0){
        q.push({nx, ny});
        visited[nx][ny] = true;
        infected++;
      }
    }
  }
  return (zero - infected - 3);
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin>>n>>m;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      cin>>miro[i][j];
      postMiro[i][j] = miro[i][j];
      if(miro[i][j] == 0){
        zero++;
      }
    }
  }

  int total = n*m;
  for(int i = 0; i < total - 2; i++){
    if(postMiro[i/m][i%m] != 0)continue;

    for(int j = i+1; j < total - 1; j++){
      if(postMiro[j/m][j%m] != 0) continue;

      for(int k = j + 1; k < total; k++){
        if(postMiro[k/m][k%m] != 0) continue;

        postMiro[i/m][i%m] = 1;
        postMiro[j/m][j%m] = 1;
        postMiro[k/m][k%m] = 1;

        safeRegion.push_back(bfs());

        postMiro[i/m][i%m] = 0;
        postMiro[j/m][j%m] = 0;
        postMiro[k/m][k%m] = 0;
      }
    }
  }
  
  sort(safeRegion.begin(), safeRegion.end());
  cout<<safeRegion[0]<<'\n';
  cout<<*max_element(safeRegion.begin(), safeRegion.end())<<"\n";
  return 0;
}