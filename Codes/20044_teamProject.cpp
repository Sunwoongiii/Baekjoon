#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int n,k;
vector<int>v;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin>>n;
  k = 2*n;
  for(int i = 0; i < k; i++){
    int a;
    cin>>a;
    v.push_back(a);
  }
  sort(v.begin(), v.end());

  int ans = 2e9;
  for(int i = 0; i < k; i++){
    ans = min(ans, v[i] + v[k-i-1]);
  }
  cout<<ans;
  return 0;
}