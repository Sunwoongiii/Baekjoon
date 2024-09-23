#include <iostream>

using namespace std;

int n, dp[1001];

int DP(int n){
  if(dp[n] != 0) return dp[n];
  return dp[n] = (DP(n-1) + DP(n-2))%10007;
}

int main(){
  cin>>n;
  dp[1] =1, dp[2] = 2, dp[3] = 3, dp[4] = 5;
  cout<<DP(n);
}