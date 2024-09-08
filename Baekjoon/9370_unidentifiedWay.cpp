#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <math.h>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <sstream>

using namespace std;
using ll = long long;

int T,n,m,t,s,g,h;
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
vector<pair<int,int>>v[50005];
int goal[2002];
int ans[2002];

int dijkstra(){
  while(!pq.empty()){
    int value = pq.top().first;
    int node = pq.top().second;
    pq.pop();

    
  }
}


int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin>>T;
  while(T--){
    cin>>n>>m>>t;
    cin>>s>>g>>h;


    for(int i = 0; i < m; i++){
      int a,b,d;
      cin>>a>>b>>d;
      v[a].push_back({b,d});
      v[b].push_back({a,d});
    }

    for(int i = 0; i < t; i++){
      cin>>goal[i];
    }
  }
}