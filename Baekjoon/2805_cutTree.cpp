#include <iostream>
using namespace std;

long long n,m;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin>>n>>m;
  long long arr[n];
  long long end = -1; 
  for(int i = 0; i < n; i++){
    cin>>arr[i];
    if(end < arr[i])end = arr[i];
  }

  long long front = 0;
  long long result = 0;
  while(front <= end){
    long long mid = (front + end)/2;
    long long sum = 0;

    for(int i = 0; i < n; i++){
      if(arr[i] > mid){
        sum += arr[i] - mid;
      }
    }
    if(sum >= m){
      result = mid;
      front = mid+1;
    }
    else{
      end = mid -1;
    }
  }
  cout<<result;
}