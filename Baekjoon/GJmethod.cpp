#include <iostream>

using namespace std;

int matrix[101][101];

int main(){
  int n;
  cin>>n;

  for(int i = 1; i <= n;i++){
    for(int j= =1; j <= n; j++){
      cin>>matrix[i][j];
    }
  }
}