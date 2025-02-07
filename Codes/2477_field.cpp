#include <iostream>
using namespace std;

pair<int,int>p[12];

int main(){
  int k,d,l,big,small;
  cin>>k;

  for(int i = 0; i < 6; i++){
    cin>>d>>l;
    p[i] = p[i+6] = {d,l};
  }

  for(int i = 3; i< 12; i++){
    if(p[i].first == p[i-2].first && p[i-1].first == p[i-3].first){
      big = p[i+1].second * p[i+2].second;
      small = p[i-1].second * p[i-2].second;
      break;
    }
  }
  cout<<k * (big - small);
}