#include <iostream>
#include <string>
using namespace std;

string doc, input;
int cnt = 0;

int main(){
  getline(cin, doc);
  getline(cin, input);

  for(int i = 0; i < doc.length(); i++){
    bool flag = true;
    for(int j = 0; j <input.length(); j++){
      if(doc[i+j] != input[j]){
        flag = false;
        break;
      }
    }
    if(flag){
      cnt++;
      i+=input.length()-1;
    }
  }
  cout<<cnt;
}