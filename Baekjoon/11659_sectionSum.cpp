#include <iostream>
using namespace std;

int n,m,i,j;
int arr[101001];

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  
  cin>>n>>m;
  for(int i = 1; i <= n; i++) cin>>arr[i];

  while(m--){
    cin>>i>>j;
    int sum = 0;
    for(int k = i; k <= j; k++) sum+=arr[k];
    cout<<sum<<"\n";
  }
}