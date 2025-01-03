#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int k,n;
  cin>>k>>n;
  vector<int>v(k);
  int maxi = 0;
  for(int i = 0; i < k; i++){
    cin>>v[i];
    maxi = max(maxi,v[i]);
  }
  ll left = 1;
  ll right = maxi;
  ll result = 0;

  while(left <= right){
    ll mid = (left+ right)/2;
    ll cnt = 0;

    for(int i = 0; i < k; i++){
      cnt += v[i]/mid;
    }
    if(cnt >= n){
      result = mid;
      left = mid+1;
    }
    else right = mid-1;
  }
  cout<<result;
  
}