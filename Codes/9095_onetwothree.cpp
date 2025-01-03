#include <iostream>

using namespace std;

int n, t, dp[12];
int f(int n){
  if(dp[n]!=0) return dp[n];
  return dp[n] = f(n-1)+f(n-2)+f(n-3);
}

int main(){
  cin>>t;
  dp[1] = 1, dp[2] = 2, dp[3] = 4;
  while(t--){
    cin>>n;
    cout<<f(n)<<endl;
  }
}