#include <iostream>
#include <vector>
using namespace std;

int N,M,B;
int house[505][505];
int t1 = 2, t2 = 1;
int t = 1e9, line = 1e9;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin>>N>>M>>B;
  int max = 0, min = 0;
  for(int i = 0; i < N; i++){
    for(int j = 0; j <M; j++){
      cin>>house[i][j];
      if(max < house[i][j]) max = house[i][j];
      else if(min > house[i][j]) min = house[i][j];
    }
  }

  for(int i = min; i <= max; i++){
    int remove = 0;
    int stack = 0;

    for(int j = 0; j < N; j++){
      for(int k = 0; k < M; k++){
        if(house[j][k] > i) remove += (house[j][k]-i);
        else if(house[j][k] < i) stack+= (i-house[j][k]);
      }
    }

    if(stack<= remove + B){
      int temp = remove*2 + stack;
      if(t > temp){
        t = temp;
        line = i;
      }
      else if(t == temp){
        line = i;
      }
    }
  }
  cout<<t<<' '<<line;
  return 0;
}