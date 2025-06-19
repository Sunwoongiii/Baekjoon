#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits>
using namespace std;

int n,m,virusCnt=0;
int miro[55][55];
int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};
bool visited[55][55];
vector<pair<int,int>>virus;
vector<int>comb;

void getInput(){
  cin>>n>>m;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      cin>>miro[i][j];
      if(miro[i][j] == 2){
        virus.push_back({i,j});
        virusCnt++;
      }
    }
  }
}

bool isInside(int a, int b){
  return(a>=0&&b>=0&&a<n&&b<n);
}

void reset(){
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      visited[i][j] = false;
    }
  }
}

int bfs(vector<pair<int,int>>&activeVirus){
  reset();
  queue<pair<int,int>>q;
  int time = 0, emptyCnt = 0;

  for(auto &v : activeVirus){
    q.push(v);
    visited[v.first][v.second] = true;
  }

  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      if(miro[i][j] == 0 || miro[i][j] == 2)emptyCnt++; // 2도 추가해야하는지 로직 체크 필요요
    }
  }
  if(emptyCnt == 0)return 0;

  while(!q.empty()){
    int size = q.size();
    while(size--){
      int x = q.front().first;
      int y = q.front().second;
      q.pop();

      for(int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(isInside(nx,ny) && !visited[nx][ny] && miro[nx][ny] != 1){
          visited[nx][ny] = true;
          q.push({nx,ny});
          if(miro[nx][ny] == 0){
            emptyCnt--;
            if(emptyCnt == 0)return time + 1;
          }
        }
      }
    }
    time++;
  }
  return INT_MAX;
}

int solve(){
  int minTime = INT_MAX;
  comb.resize(virusCnt, 0);
  fill(comb.end()-m, comb.end(), 1);

  do{
    vector<pair<int,int>>activeVirus;
    for(int i = 0; i < virusCnt; i++){
      if(comb[i] == 1) activeVirus.push_back(virus[i]);
    }
    int time = bfs(activeVirus);
    minTime = min(minTime, time);
  }
  while(next_permutation(comb.begin(), comb.end()));
  return(minTime == INT_MAX ? -1 : minTime);
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  getInput();
  cout<<solve();
  return 0;
}