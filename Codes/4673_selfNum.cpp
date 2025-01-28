#include <iostream>
using namespace std;

int D(int num){
  int sum = num;

  while(num != 0){
    sum = sum + (num%10);
    num = num / 10;
  }
  return sum;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);


  bool check[10001] = {false, };
  for(int i = 1; i < 10001; i++){
    int n = D(i);
    if(n < 10001)check[n] = true;
  }
  for(int i = 1; i < 10001; i++){
    if(!check[i])cout<<i<<'\n';
  }
}