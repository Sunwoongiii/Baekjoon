#include <iostream>
#include <algorithm>
using namespace std;

int N,M;
int FW[505][505];

void getInput(){
  cin>>N>>M;
  for(int i = 1; i <= N; i++){
    for(int j = 1; j <= N; j++){
      if(i != j)FW[i][j] = 1e9;
    }
  }

  for(int i = 0; i < M; i++){
    int a,b,c;
    cin>>a>>b>>c;
    FW[a][b] = c;
    FW[b][a] = c;
  }
}

