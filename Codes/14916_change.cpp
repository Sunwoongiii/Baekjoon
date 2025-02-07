#include <iostream>
using namespace std;

int main(){
  int n;
  cin>>n;
  int dp[100001];
  fill(dp, dp + n +1, -1);

  dp[0] = -1; dp[1] = -1; dp[2] = 1; dp[3] = -1; dp[4] = 2;
  dp[5] = 1; dp[6] = 3; dp[7] = 2; dp[8] = 4; dp[9] = 3;

  for(int i = 10; i <= n; i++){
    dp[i] = dp[i-5] + 1;
  }
  cout<<dp[n];
  return 0;
}