#include <iostream>
#include <map>
#include <algorithm>
using namespace std;
int n,nn;
string str1,str2;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin>>n;
  while(n--){
    cin>>nn;
    map<string,int>m;
    while(nn--){
      cin>>str1>>str2;
      m[str2]++;
    }
    int sum = 1;
    for(auto x : m){
      sum *= x.second + 1;
    }
    cout<<sum-1<<"\n";
  }
}