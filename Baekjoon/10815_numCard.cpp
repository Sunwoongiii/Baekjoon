#include <iostream>
#include <unordered_set>

using namespace std;

int m,n, arr[500005], arr2[500005];

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin>>m;
  for(int i = 0; i < m; i++){
    cin>>arr[i];
  }
  cin>>n;
  for(int i = 0; i < n; i++){
    cin>>arr2[i];
  }
  unordered_set<int> set1(arr, arr+m);
  for(int i = 0; i < n; i++){
    if(set1.find(arr2[i]) != set1.end()) cout<<1<<' ';
    else cout<<0<<' ';
  }
  return 0;
}