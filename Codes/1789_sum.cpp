#include <iostream>
using namespace std;
using ll = long long;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  ll S;
  cin>>S;

  ll ans = 0, num = 1;
  int cnt = 0;

  while(true){
    ans += num;
    cnt++;
    if(ans > S){
      cnt--;
      break;
    }
    num++;
  }
  cout<<cnt;
}