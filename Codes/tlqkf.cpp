#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
  while(true){
    int a,b,c;
    cin>>a>>b>>c;

    if(a == 0 && b == 0 && c == 0)return 0;
    else{
      vector<int>v;
      v.push_back(a); v.push_back(b); v.push_back(c); sort(v.begin(), v.end(), greater<int>());
      if(v[0] >= v[1] + v[2]){
        cout<<"Invalid\n";
        continue;
      }
      else if((v[0] == v[1] && v[1] != v[2]) || (v[1] == v[2] && v[1] != v[0])){
        cout<<"Isosceles\n";
        continue;
      }
      else if(v[0] == v[1] && v[1] == v[2]){
        cout<<"Equilateral\n";
        continue;
      }
      else{
        cout<<"Scalene\n";
        continue;
      }
    }
  }
}