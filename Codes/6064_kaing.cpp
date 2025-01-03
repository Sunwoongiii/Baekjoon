#include <iostream>
using namespace std;

int T,M,N,x,y;

int gcd(int a, int b){
  if(b == 0)return a;
  return gcd(b, a%b);
}

int lcm(int a, int b){
  return (a*b)/gcd(a,b);
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin>>T;
  while(T--){
    cin>>M>>N>>x>>y;
    int ans = -1;
    int maxi = lcm(M,N);
    for(int i = x; i <= maxi; i+=M){
      int ny = i%N;
      if(ny == 0)ny = N;
      if(ny == y){
        ans = i;
        break;
      }
    }
    cout<<ans<<'\n';
  }
}