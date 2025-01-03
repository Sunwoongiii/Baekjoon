#include <limits.h>
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

int n;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin>>n;
  vector<int>dp(n+1,0);
  dp[1] = 1;

  for(int i = 2; i <= n; i++){
    int mini = INT_MAX;
    for(int j = 1; j*j <= i; j++){
      int tmp = i - j*j;
      mini = min(mini, dp[tmp]);
    }
    dp[i] = mini+1;
  }
  cout<<dp[n];
}