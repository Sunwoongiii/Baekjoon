#include <iostream>
#include <algorithm>
#include <limits>

using namespace std;

int n, m;
int miro[101][101];//i -> j
int inf = 2e8-1;

void initialize(){
  for(int i = 1; i <= n; i++){
    for(int j = 1; j<=n;j++){
      if(i == j) miro[i][j] = 0;
      else miro[i][j] = inf;
    }
  }
}

void inputNode(){
  while(m--){
    int a,b,c;
    cin>>a>>b>>c;
    miro[a][b] = min(miro[a][b], c);
  }
}

void floydWarshall(){
  for(int k = 1; k <= n; k++){
    for(int i = 1; i <= n; i++){
      for(int j = 1; j <= n; j++){
        if(miro[i][j] > miro[i][k] + miro[k][j]){
          miro[i][j] = miro[i][k] + miro[k][j];
        }
      }
    }
  }
}

void printPath(){
  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= n; j++){
      if(miro[i][j] == inf) cout<<"0 ";
      else cout<<miro[i][j]<<" ";
    }
    cout<<"\n";
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin>>n>>m;
  initialize();
  inputNode();
  floydWarshall();
  printPath();
  return 0;
}