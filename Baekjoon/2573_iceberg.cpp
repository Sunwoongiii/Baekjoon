#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n,m;
int miro[303][303][11];
bool visited[303][303];

int bfs();

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin>>n>>m;

  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      cin>>miro[i][j][0];
    }
  }
}