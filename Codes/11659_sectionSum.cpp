#include <iostream>
using namespace std;
using ll = long long;
int n,m,i,j;
ll arr[100100];


int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin>>n>>m;
  for(int i = 1; i <= n; i++){
    int x;
    cin>>x;
    arr[i] = arr[i-1] + x;
  }

  while(m--){
    cin>>i>>j;
    cout<<arr[j]-arr[i-1]<<"\n";
  }
}