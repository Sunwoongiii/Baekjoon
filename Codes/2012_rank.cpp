#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;
using  ll = long long;

int n;
vector<int>v;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin>>n;
  for(int i = 0; i<n; i++){
    int x;
    cin>>x;
    v.push_back(x);
  }
  sort(v.begin(), v.end());
  ll ans = 0;
  for(int i = 0; i<n; i++){
    ans += abs(i+1 - v[i]);
  }
  cout<<ans;
}