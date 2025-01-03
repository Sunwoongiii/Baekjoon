#include <iostream>
using namespace std;

int main(){
  string str;
  int len;
  cin>>str;
  len = str.length();

  for(int i = 0; i < len; i++){
    if(i % 10 == 0 && i != 0)cout<<'\n'<<str[i];
    else cout<<str[i];
  }
}