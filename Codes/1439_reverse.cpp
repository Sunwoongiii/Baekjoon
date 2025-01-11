#include <iostream>
#include <string>
using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  string str;
  int zero = 0, one = 0;
  char prev = ' ';

  cin>>str;

  for(char c : str){
    if(c == '0'){
      if(prev != '0') zero++;
    }
    else if(c == '1'){
      if(prev != '1') one++;
    }
    prev = c;
  }

  int ans = zero > one ? one : zero;
  cout<<ans;
}