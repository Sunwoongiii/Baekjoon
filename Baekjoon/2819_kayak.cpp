#include <iostream>
using namespace std;

int n,s,r,cnt=0,arr[12];

int main(){
  cin>>n>>s>>r;
  
  for(int i = 1; i <= n; i++)arr[i] = 0;

  for(int i = 0; i < s;i ++){
    int a;
    cin>>a;
    arr[a] = -1;
  }

  for(int i = 0; i < r; i++){
    int a;
    cin>>a;
    if(arr[a] == -1) arr[a] = 0;
    else arr[a] = 1;
  }

  for(int i = 1; i <= n; i++){
    if(arr[i] == -1){
      if(i>1 && arr[i-1] == 1){
        arr[i] = 0;
        arr[i-1] = 0;
      }
      else if(i < n && arr[i+1] == 1){
        arr[i] = 0;
        arr[i+1] = 0;
      }
    }
  }
  for(int i = 1; i <= n; i++){
    if(arr[i] == -1)cnt++;
  }
  cout<<cnt;
}