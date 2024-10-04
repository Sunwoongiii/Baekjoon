#include <iostream>
#include <queue>
#include <cstdlib>
#include <algorithm>
using namespace std;

class Point{
  public:
  int x;
  int y;
};

Point store[100];
Point home;
Point festival;
bool visited[100];

bool bfs(int n){
  queue<pair<int,int>>q;
  q.push({home.x, home.y});

  while(!q.empty()){
    int x = q.front().first;
    int y = q.front().second;
    q.pop();

    if(abs(festival.x - x) + abs(festival.y-y) <= 1000) return true;

    for(int i = 0; i < n; i++){
      if(visited[i]) continue;
      if(abs(store[i].x - x) + abs(store[i].y-y) <= 1000){
        visited[i] = true;
        q.push({store[i].x, store[i].y});
      }
    }
  }
  return false;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int t;
  cin>>t;
  
  while(t--){
    int n;
    cin>>n;
    cin>>home.x>>home.y;
    for(int i = 0; i < n; i++){
      cin>>store[i].x>>store[i].y;
    }
    cin>>festival.x>>festival.y;

    bool canVisit = bfs(n);
    if(canVisit)cout<<"happy\n";
    else cout<<"sad\n";
    fill(visited,visited+n,false);
  }
  return 0;
}