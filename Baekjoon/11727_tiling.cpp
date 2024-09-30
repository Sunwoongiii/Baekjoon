#include <iostream>
using namespace std;

int n;
int dp[1010];

int DP(int x){
  if(dp[x]!=0) return dp[x];
  else return dp[x] = (DP(x-2)*2 + DP(x-1))%10007;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  dp[1] = 1;
  dp[2] = 3;

  cin>>n;
  cout<<DP(n);
}