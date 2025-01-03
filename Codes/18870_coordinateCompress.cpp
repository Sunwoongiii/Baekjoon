#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

int n;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin>>n;
  vector<int>v(n),ans(n);
  set<int>s;

  for(int i = 0; i < n; i++){
    cin>>v[i];
    s.insert(v[i]);
  }

  vector<int>temp(s.begin(),s.end());
  sort(temp.begin(), temp.end());

  for(int i = 0; i < n; i++){
    ans[i] = lower_bound(temp.begin(), temp.end(), v[i])-temp.begin();
  }

  for(int num : ans)cout<<num<<' ';
}