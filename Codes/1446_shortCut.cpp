#include <iostream>
#include <vector>

using namespace std;

const int inf = 10005;
int n,d,from,to,cost;
vector<int>m(10005, inf);
vector<pair<int,int>>v[100005];

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin>>n>>d;
  for(int i = 0; i < n; i++){
    cin>>from>>to>>cost;
    if(to > d || to - from < cost) continue;
    v[to].push_back({from, cost});
  }

  m[0] = 0;
  for(int i = 1; i <= d; i++){
    m[i] = m[i-1] + 1;
    for(int j = 0; j < v[i].size(); j++){
      m[i] = min(m[i], m[v[i][j].first] + v[i][j].second);
    }
  }
  cout<<m[d];
}