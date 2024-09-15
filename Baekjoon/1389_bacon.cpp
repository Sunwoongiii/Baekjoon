#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n,m,inf = 2e9;
int miro[101][101];

void initialize(){
  for(int i = 1 ; i<= n; i++){
    for(int j = 1; j <= n; j++){
      if(i == j) miro[i][j] = 0;
      else miro[i][j] = inf;
    }
  }
}

void inputNode(){
  while(m--){
    int a,b;
    cin>>a>>b;
    miro[a][b] = 1;
    miro[b][a] = 1;
  }
}

void floydWarshall(){
  for(int k = 1; k <= n; k++){
    for(int i = 1; i <= n; i++){
      for(int j = 1; j <= n; j++){
        if(miro[i][k] != inf && miro[k][j] != inf){
          miro[i][j] = min(miro[i][j], miro[i][k] + miro[k][j]);
        }
      }
    }
  }
}

int printAns(){
  int mini = inf;
  int person = 0;

  for(int i = 1; i <= n; i++){
    int sum = 0;
    for(int j = 1; j <= n; j++){
      sum += miro[i][j];
    }
    if(sum < mini){
      mini = sum;
      person = i;
    }
  }
  return person;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin>>n>>m;
  initialize();
  inputNode();
  floydWarshall();
  cout<<printAns();
  return 0;
}