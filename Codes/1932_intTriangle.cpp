#include <iostream>
#include <algorithm>
using namespace std;

int n, ans = -1;
int arr[505][505];
int dp[505][505];

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin>>n;
  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= i; j++){
      cin>>arr[i][j];
    }
  }

  dp[1][1] = arr[1][1];
  for(int i = 2; i <= n; i++){
    for(int j = 1; j <= i; j++){
      dp[i][j] = arr[i][j];
      if(j >  1) dp[i][j] = max(dp[i][j], dp[i-1][j-1]+arr[i][j]);
      if(j <= i-1) dp[i][j] = max(dp[i][j], dp[i-1][j] + arr[i][j]);
    }
  }
  for(int i = 1; i <= n; i++){
    ans = max(ans, dp[n][i]);
  }
  cout<<ans;
}