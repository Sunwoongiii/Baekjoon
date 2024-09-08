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

int n,d;
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
int ans[10001];
bool visited[10001];
vector<pair<int,int>>v[10001];

void dijkstra(){

}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin>>n>>d;
  for(int i = 0; i < n; i++){
    int a,b,c;
    cin>>a>>b>>c;
    if(b-a > c) v[a].push_back({c,b});
  }

  
}