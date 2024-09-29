#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int V,e;
vector<pair<int,int>>v[100001];

void getInput(){
  cin>>V>>e;
  for(int i = 0; i < e; i++){
    int a,b,c;
    cin>>a>>b>>c;
    v[a].push_back({c,b});
    v[b].push_back({c,a});
  }
}