#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
using namespace std;

int parent[10001];
vector<tuple<int,int,int>> v;
int V,E,ans=0;

int find(int x){
  if(parent[x] == x) return x;
  else return parent[x] = find(parent[x]);
}

void unite(int x, int y){
  x = find(x);
  y = find(y);

  parent[y] = x;
}

bool UF(int x, int y){
  x = find(x);
  y = find(y);

  return x == y ? true : false;
}

void getInput(){
  cin>>V>>E;

  for(int i = 1; i <= V; i++)parent[i] = i;

  for(int i = 0; i < E; i++){
    int a,b,c;
    cin>>a>>b>>c;
    v.push_back({c,a,b});
  }

  sort(v.begin(), v.end());
}

void kruskal(){
  for(const auto& edge : v){
    int c = get<0>(edge);
    int a = get<1>(edge);
    int b = get<2>(edge);

    if(!UF(a,b)){
      unite(a,b);
      ans+=c;
    }
  }
}

void sol(){
  getInput();
  kruskal();
  cout<<ans;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  sol();
}