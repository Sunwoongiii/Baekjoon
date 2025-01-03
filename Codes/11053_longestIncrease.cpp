#include <algorithm>
#include <iostream>

using namespace std;

int n;
int arr[1010];
int dp[1010];

void input(){
  cin>>n;
  for(int i = 1; i <= n; i++){
    cin>>arr[i];
  }
}

void solve(){
  int ans = 0;
  for(int i = 1; i <= n; i++){
    dp[i] = 1;
    for(int j = i-1; j >= 1; j--){
      if(arr[i] > arr[j]){
        dp[i] = max(dp[i], dp[j]+1);
      }
    }
    ans = max(dp[i],ans);
  }
  cout<<ans;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  input();
  solve();
}