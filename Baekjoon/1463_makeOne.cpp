  #include <iostream>
  #include <algorithm>

  using namespace std;
  using ll = long long;

  int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int n;
    cin>>n;
    int dp[1000001] = {0};

    for(int i = 2; i <= n; i++){
      dp[i] = dp[i-1] + 1;
      if(i % 2 == 0) dp[i] = min(dp[i], dp[i/2]+1);
      if(i % 3 == 0) dp[i] = min(dp[i], dp[i/3]+1);
    }
    cout<<dp[n];
    return 0;
  }