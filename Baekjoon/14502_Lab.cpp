#include <queue>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int n, m;
int zero = 0;
int size = 0;
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
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      visited[i][j] = false;
      postMiro[i][j] = miro[i][j];
    }
  }
  while(!q.empty()) q.pop();
}

int bfs(){
  size = 0;

  while(!q.empty()){
    int x = q.front().first;
    int y = q.front().second;
    q.pop();
    size++;

    for(int i = 0; i < 4; i++){
      int nx = x + dx[i];
      int ny = y + dy[i];

      if(isInside(nx, ny) && !visited[nx][ny] && miro[nx][ny] != 1){
        q.push({nx, ny});
        visited[nx][ny] = true;
      }
    }
  }
  return ((n*m) - size);
}

int factorial(int a){
  if(a == 1){
    return 1;
  }
  else{
    return a * factorial(a-1);
  }
}

int combination(int a, int b){
  return (factorial(a) / (factorial(a-b) * factorial(b)));
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
      if(miro[i][j] == 2){
        q.push({i,j});
        visited[i][j] = true;
      }
    }
  }

  int testCase = combination(zero, 3);
  

  
  
  sort(safeRegion.begin(), safeRegion.end());
  cout<<safeRegion[0];
  return 0;
}