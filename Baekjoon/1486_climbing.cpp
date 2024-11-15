#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <tuple>
#include <math.h>
using namespace std;

int n,m,t,d;
vector<vector<int>>miro;
vector<vector<int>>go;
vector<vector<int>>back;
priority_queue<tuple<long long,int,int>,vector<tuple<long long,int,int>>,greater<tuple<long long,int,int>>>pq;
int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};

void getInput(){
  cin>>n>>m>>t>>d;
  miro.resize(n, vector<int>(m));
  go.resize(n, vector<int>(m,1e9));
  back.resize(n, vector<int>(m,1e9));

  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      char temp;
      cin>>temp;
      if(islower(temp))miro[i][j] = temp- 'a'+26;
      else miro[i][j] = temp-'A';
    }
  }
}

bool isInside(int a, int b){
  return(a>=0&&b>=0&&a<n&&b<m);
}

void reset(){
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++) back[i][j] = 1e9;
  }
  while(!pq.empty())pq.pop();
}

void TOGO(){
  pq.push({0,0,0});
  go[0][0] = 0;

  while(!pq.empty()){
    int x, y;
    long long time;
    tie(time, x, y) = pq.top();
    pq.pop();

    for(int i = 0; i < 4; i++){
      int nx = x + dx[i];
      int ny = y + dy[i];

      if(isInside(nx,ny)){
        int h = abs(miro[nx][ny] - miro[x][y]);
        int cost = (miro[nx][ny] > miro[x][y]) ? (long long)h*h : 1;

        if(h <= t && go[nx][ny] > go[x][y] + cost){
          go[nx][ny] = go[x][y] + cost;
          pq.push({go[nx][ny], nx, ny});
        }
      }
    }
  }
}

long long BACK(int a, int b){
  reset();
  pq.push({0,a,b});
  back[a][b] = 0;

  while(!pq.empty()){
    int x, y;
    long long time;
    tie(time,x,y) = pq.top();
    pq.pop();

    for(int i = 0; i < 4; i++){
      int nx = x + dx[i];
      int ny = y + dy[i];

      if(isInside(nx,ny)){
        int h = abs(miro[nx][ny] - miro[x][y]);
        long long cost = (miro[nx][ny] > miro[x][y]) ? (long long)h*h : 1;

        if(h <= t && back[nx][ny] > back[x][y] + cost){
          back[nx][ny] = back[x][y] + cost;
          pq.push({back[nx][ny], nx, ny});
        }
      }
    }
  }
  return back[0][0];
}

void sol(){
  getInput();
  TOGO();

  // for(int i = 0; i < n; i++){
  //   for(int j = 0; j < m; j++){
  //     cout<<miro[i][j]<<' ';
  //   }
  //   cout<<'\n';
  // }
  // cout<<'\n';

  // for(int i = 0; i < n; i++){
  //   for(int j = 0; j < m; j++){
  //     cout<<go[i][j]<<' ';
  //   }
  //   cout<<'\n';
  // }

  // cout<<'\n';

  // for(int i = 0; i < n; i++){
  //   for(int j = 0; j < m; j++){
  //     cout<<BACK(i,j)<<' ';
  //   }
  //   cout<<'\n';
  // }
  // cout<<'\n';

  // int maxi = -1;
  // for(int i = 0; i < n; i++){
  //   for(int j = 0; j < m; j++){
  //     int temp = go[i][j] + BACK(i,j);
  //     if(temp <= d)cout<<temp<<' ';
  //     else cout<<-1;
  //   }
  //   cout<<'\n';
  // }

  int maxi = -1;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      long long temp = go[i][j] + BACK(i,j);
      if(temp<=d){
        maxi = max(miro[i][j], maxi);
      }
    }
  }
  cout<<maxi;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  sol();
}