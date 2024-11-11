#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int n,m;
char miro[110][110];
bool visited[110][110];
queue<pair<int,int>>qB;
queue<pair<int,int>>qW;
int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};
vector<int>vB;
vector<int>vW;
int sumB,sumW;

bool isInside(int a, int b){
  return(a>=0&&b>=0&&a<n&&b<m);
}

void getInput(){
  cin>>m>>n;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      cin>>miro[i][j];
    }
  }
}

int bfsB(int a, int b){
  int size = 0;
  if(visited[a][b])return 0;
  visited[a][b] = true;
  qB.push({a,b});
  while(!qB.empty()){
    int x = qB.front().first;
    int y = qB.front().second;
    qB.pop();
    size++;

    for(int i = 0; i < 4; i++){
      int nx = x + dx[i];
      int ny = y + dy[i];

      if(isInside(nx,ny) && !visited[nx][ny] && miro[nx][ny] == 'B'){
        qB.push({nx,ny});
        visited[nx][ny] = true;
      }
    }
  }
  return size;
}

int bfsW(int a, int b){
  int size = 0;
  if(visited[a][b]) return 0;
  visited[a][b] = true;
  qW.push({a,b});
  while(!qW.empty()){
    int x = qW.front().first;
    int y = qW.front().second;
    qW.pop();
    size++;

    for(int i = 0; i < 4; i++){
      int nx = x + dx[i];
      int ny = y + dy[i];

      if(isInside(nx,ny) && !visited[nx][ny] && miro[nx][ny] =='W'){
        qW.push({nx,ny});
        visited[nx][ny] = true;
      }
    }
  }
  return size;
}

void solve(){
  getInput();
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      if(miro[i][j] == 'B'){
        vB.push_back(bfsB(i,j));
      }
      else{
        vW.push_back(bfsW(i,j));
      }
    }
  }

  for(int num : vB){
    sumB += num*num;
  }
  for(int num : vW){
    sumW += num*num;
  }
  cout<<sumW<<' '<<sumB;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  solve();
}