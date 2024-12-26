#include <iostream>
#include <algorithm>
using namespace  std;

int n,m;
int first[10];
int arr[10];
bool visited[10];

void dfs(int num, int k){
  if(k==m){
    for(int i = 0; i < m; i++){
      cout<<arr[i]<<' ';
    }
    cout<<'\n';
  }
  else{
    for(int i = 1; i <= n; i++){
      if(!visited[i]){
        visited[i] = true;
        arr[k] = first[i-1];
        dfs(i+1,k+1);
        visited[i] = false;
      }
    }
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  
  cin>>n>>m;
  for(int i = 0; i < n; i++)cin>>first[i];
  sort(first, first+n);
  dfs(1,0);
}