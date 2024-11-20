#include <iostream>
#include <sstream>
#include <algorithm>
#include <deque>
using namespace std;

int t,n;
string str1,str2;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin>>t;
  while(t--){
    cin>>str1>>n>>str2;
    deque<int>dq;
    
    bool possible = true, dir = true;
    string tmp = "";

    for(int i = 1; i < str2.size(); i++){
      if(str2[i] == ',' || str2[i] == ']'){
        if(tmp != ""){
          dq.push_back(stoi(tmp));
          tmp = "";
        }
      }

      else{
        tmp += str2[i];
      }
    }

    for(int i = 0; i < str1.size(); i++){
      if(str1[i] == 'R'){
        dir = !dir;
      }
      else if(str1[i] == 'D'){
        if(dq.empty()){
          possible = false;
          break;
        }
        else{
          if(dir)dq.pop_front();
          else dq.pop_back();
        }
      }
    }
    if(!possible)cout<<"error\n";
    else{
      if(!dir)reverse(dq.begin(), dq.end());
      cout<<"[";
      for(int i = 0; i < dq.size(); i++){
        if(i == dq.size()-1)cout<<dq[i];
        else cout<<dq[i]<<",";
      }
      cout<<"]\n";
    }
  }
}