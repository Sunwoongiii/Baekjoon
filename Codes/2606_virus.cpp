#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n,m,cnt;
vector<int>v[10001];
bool visited[101];
queue<int>q;
int arr[101];

void getInput(){
  cin>>n>>m;
  for(int i = 0; i < m; i++){
    int a,b;
    cin>>a>>b;
    v[a].push_back(b);
    v[b].push_back(a);
  }
}

int bfs(){
  q.push(1);
  visited[1] = true;

  while(!q.empty()){
    int node = q.front();
    q.pop();
    cnt++;

    for(int i = 0; i < v[node].size(); i++){
      int next = v[node][i];

      if(!visited[next]){
        visited[next] = true;
        q.push(next);
      }
    }
  }
  return cnt-1;
}

void sol(){
  getInput();
  cout<<bfs();
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  sol();
}