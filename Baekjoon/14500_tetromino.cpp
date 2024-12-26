#include <iostream>
#include <algorithm>
using namespace std;

int n,m;
int miro[505][505];

void getInput(){
  cin>>n>>m;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      cin>>miro[i][j];
    }
  }
}

