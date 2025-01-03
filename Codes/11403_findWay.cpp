#include <iostream>

using namespace std;

int miro[101][101];

int main(){
  int n;
  cin>>n;
  for(int i = 0; i < n; i++){
    for(int j = 0 ; j < n; j++){
      cin>>miro[i][j];
    }
  }

  for(int k = 0; k < n; k ++){
    for(int i = 0; i < n; i++){
      for(int j = 0 ; j < n; j++){
        if(miro[i][k] && miro[k][j]) miro[i][j] = 1;
      }
    }
  }
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      cout<<miro[i][j]<<" ";
    }
    cout<<"\n";
  }
  return 0;
}