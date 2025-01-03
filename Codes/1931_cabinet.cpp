#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int n;
vector<pair<int,int>>v;

int main(){
  cin>>n;
  while(n--){
    int start, end;
    cin>>end>>start;
    v.push_back({start, end});
  }
  sort(v.begin(), v.end());

  int time = v[0].first;
  int cnt = 1;

  for(int i = 1; i < v.size(); i++){
    if(v[i].second >= time){
      cnt++;
      time = v[i].first;
    }
  }
  cout<<cnt;
}