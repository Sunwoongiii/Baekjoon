#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;
using ll = long long;

int N;
ll arr[100001];
ll leftPtr,rightPtr;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin>>N;
  for(int i = 0; i < N; i++){
    cin>>arr[i];
  }

  int left = 0;
  int right = N-1;
  ll ans = abs(arr[left] + arr[right]);
  leftPtr = arr[left];
  rightPtr = arr[right];

  while(left < right){
    ll tmp = arr[left] + arr[right];

    if(abs(tmp) < ans){
      ans = abs(tmp);
      leftPtr = arr[left];
      rightPtr = arr[right];
    }

    if(tmp < 0) left++;
    else right--;
  }

  cout<<leftPtr<<' '<<rightPtr;
}