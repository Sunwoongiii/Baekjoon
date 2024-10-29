#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n,m;
vector<int>v;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin>>n;
  for(int i = 0; i < n; i++){
    int a;
    cin>>a;
    v.push_back(a);
  }
  sort(v.begin(), v.end());

  cin>>m;
  for(int i = 0; i < m; i++){
    int a;
    cin>>a;
    auto lower = lower_bound(v.begin(), v.end(), a);
    auto upper = upper_bound(v.begin(), v.end(), a);
    cout<<upper-lower<<" ";
  }
}