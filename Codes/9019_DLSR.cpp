#include <iostream>
#include <queue>
#include <string>
#include <cstring>
using namespace std;

int n,tar;
bool visited[10000];

void bfs(){
  queue<pair<int,string>>q;
  q.push({n,""});
  visited[n] = true;

  while(!q.empty()){
    int node = q.front().first;
    string op = q.front().second;
    q.pop();

    if(node == tar){
      cout<<op<<'\n';
      return;
    }

    int D,S,L,R,temp;

    D = (node * 2) % 10000;
    if(!visited[D]){
      visited[D] = true;
      q.push({D,op+"D"});
    }

    S = node - 1 < 0 ? 9999 : node -1;
    if(!visited[S]){
      visited[S] = true;
      q.push({S, op+"S"});
    }

    L = (node %1000)*10 + (node / 1000);
    if(!visited[L]){
      visited[L] = true;
      q.push({L,op+"L"});
    }

    R = node/10 + (node%10)*1000;
    if(!visited[R]){
      visited[R] = true;  
      q.push({R,op+"R"});
    }
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int T;
  cin>>T;
  while(T--){
    cin>>n>>tar;
    fill(visited, visited+10000, false);
    bfs();
  }
}