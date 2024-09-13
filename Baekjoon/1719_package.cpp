#include <iostream>
#include <limits>

using namespace std;

int n,m,miro[201][201], inf = 9e8, nextNode[201][201];

void initialize(){
  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= n; j++){
      if(i == j)miro[i][j] = 0;
      else miro[i][j] = inf;
    }
  }
}

void inputNode(){
  while(m--){
    int a,b,c;
    cin>>a>>b>>c;
    miro[a][b] = miro[b][a] = c;
    nextNode[a][b] = b;
    nextNode[b][a] = a;
  }
}

void floydWarshall(){
  for(int k = 1; k <= n; k++){
    for(int i = 1; i <= n; i++){
      for(int j = 1; j <= n; j++){
        if(miro[i][j] > miro[i][k] + miro[k][j]){
          miro[i][j] = miro[i][k] + miro[k][j];
          if(i != k) nextNode[i][j] = nextNode[i][k];
        }
      }
    }
  }
}

void printPath(){
  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= n; j++){
      if(i == j) cout<<"- ";
      else cout<<nextNode[i][j]<<" ";
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