#include <iostream>
using namespace std;
using ll = long long;
ll fiboarr[50] = {0,1,};

ll fibo(int n){
  if(n==0 || n==1) return fiboarr[n];
  else if(fiboarr[n] == 0) fiboarr[n] = fibo(n-1) + fibo(n-2);
  
  return fiboarr[n];
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int t;
  cin>>t;
  int tmp;
  for(int i = 0; i < t; i++){
    cin>>tmp;
    if(tmp == 0) cout<<"1 0"<<"\n";
    else cout<<fibo(tmp-1)<<" "<<fibo(tmp)<<"\n";
  }
  return 0;
}