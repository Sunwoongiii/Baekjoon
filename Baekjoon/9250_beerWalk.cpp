#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

int t,n,beer = 20,homeX,homeY,targetX,targetY;
vector<pair<int,int>>v;

void getInput(){
  cin>>n>>homeX>>homeY;
  for(int i = 0; i < n; i++){
    int x,y;
    cin>>x>>y;
    v.push_back({x,y});
  }
  cin>>targetX>>targetY;
}

 

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin>>t;
  while(t--){
    getInput();
  }
}