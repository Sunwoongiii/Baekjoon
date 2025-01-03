#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
using ll = long long;

int V,e;
vector<vector<int>>v;

void getInput(){
  cin>>V>>e;
  
  v.resize(n, vector<int>(n,0));
  for(int i = 1; i <= V; i++){
    for(int j = 1; j <= V; j++){
      if(i == j)v[i][j] = 0;
      else miro[i][j] = 1e9;
    }
  }

  for(int i = 0; i < e; i++){
    int a,b,c;
    cin>>a>>b>>c;
    v[a][b] = c;
    v[b][a] = c;
  }
}

void floydWarshall(){
  for(int k = 1; k <= V; k++){
    for(int i = 1; i <=V; k++){
      for(int j = 1; j <=V; j++){
        if(v[i][k] != 1e9 && v[k][j] != 1e9){
          v[i][j] = min(v[i][j], v[i][k] + v[k][j]);
        }
      }
    }
  }

  for(int i = 1; i <= V; i++){
    if(v[i][i] < 0)return;
  }
}