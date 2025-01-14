#include <iostream>
using namespace std;
using ll = long long;

ll mod_calc(ll a, ll b, ll c){
  ll ans = 1;
  a = a % c;

  while(b > 0){
    if(b %2 == 1){
      ans = (ans * a) % c;
    }
    b /= 2;
    a = (a*a)%c;
  }
  return ans;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  ll a,b,c;
  cin>>a>>b>>c;
  cout<<mod_calc(a,b,c);
}