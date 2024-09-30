#include <iostream>
using namespace std;
using ll = long long;

ll dp[110] = {0,1,1,1,2,2,3,4,5,7,9,};
int T;
ll n;

ll PadoVan(ll x){
  if(x < 4) return dp[x];
  else if(dp[x] != 0) return dp[x];
  else{
    dp[x] = PadoVan(x-2) + PadoVan(x-3);
    return dp[x];
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin>>T;
  while(T--){
    cin>>n;
    cout<<PadoVan(n)<<"\n";
  }
}