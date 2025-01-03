#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n,m;
vector<int>v;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  
  cin>>n;
  for(int i=0; i<n; i++){
    int a;
    cin>>a;
    v.push_back(a);
  }
  sort(v.begin(), v.end());
  
  cin>>m;
  for(int i =0; i <m; i++){
    int a;
    cin>>a;
    if(binary_search(v.begin(), v.end(), a))cout<<1<<"\n";
    else cout<<0<<"\n";
  }
  return 0;
}