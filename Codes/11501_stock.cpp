#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int T,n;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin>>T;
  while(T--){
    cin>>n;
    vector<int>v;

    for(int i = 0; i < n; i++){
      int x;
      cin>>x;
      v.push_back(x);
    }

    long long result = 0;
    int maxi = -1;

    for(int i = n-1; i >= 0; i--){
      maxi = max(maxi, v[i]);
      result += maxi - v[i];
    }
    cout<<result<<'\n';
  }
}