#include <iostream>
using namespace std;
using ll = long long;

int main(){
  int n;
  ll dp[99];

  cin>>n;
  dp[0] = 0; dp[1] = 1; dp[2] = 1;

  for(int i = 3; i <= n; i++){
    dp[i] = dp[i-1] + dp[i-2];
  }
  cout<<dp[n];
}