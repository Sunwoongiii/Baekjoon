#include <iostream>
#include <string>
using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int n,m;
  string str;
  cin>>n>>m>>str;

  int ans = 0;

  for(int i = 0; i < m; i++){
    int k = 0;
    if(str[i] == 'O')continue;
    while(str[i+1] == 'O' && str[i+2] == 'I'){
      k++;
      if(k == n){
        ans++;
        k--;
      }
      i+=2;
    }
  }
  cout<<ans;
}