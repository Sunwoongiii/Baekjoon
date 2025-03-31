#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N,M;
vector<pair<int,int>>v[100001];

void getInput(){
  cin>>N>>M;
  for(int i = 0; i < M; i++){
    int a,b,c;
    cin>>a>>b>>c;
    v[a].push_back({c,b});
    v[b].push_back({c,a});
  }
}

