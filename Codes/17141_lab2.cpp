#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n,m,zero,virus,wall;
int miro[55][55];
bool visited[55][55];
vector<int> time;
vector<pair<int,int>>V;

void getInput(){
  cin>>n>>m;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      cin>>miro[i][j];
      if(miro[i][j] == 0)zero++;
      else if(miro[i][j] == 2){
        virus++;
        V.push_back({i,j});
      }
      else wall++;
    }
  }
}

bool isInside(int a, int b){
  return(a>=0&&b>=0&&a<n&&b<n);
}

void reset(){
  
}