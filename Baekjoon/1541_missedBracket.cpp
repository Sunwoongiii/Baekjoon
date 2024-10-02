#include <iostream>
#include <string>
using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  
  string str,num;
  cin>>str;

  int result = 0;
  bool minus = false;

  for(int i = 0; i <= str.size(); i++){
    if(str[i] == '-' || str[i] == '+' || i == str.size()){
      if(minus){
        result -= stoi(num);
        num = "";
      }
      else{
        result+=stoi(num);
        num = "";
      }
    }
    else{
      num+=str[i];
    }
    if(str[i] == '-') minus = true;
  }
  cout<<result;
}