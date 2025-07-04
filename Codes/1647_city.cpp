#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;

int n,m,ans = 0;
vector<tuple<int,int,int>>v;
int parent[100100];

int find(int x){
  if(parent[x] == x)return x;
  else return parent[x] = find(parent[x]);
}

void unite(int x, int y){
  x = find(x);
  y = find(y);

  y = parent[x];
}

bool UF(int x, int y){
  x = find(x);
  y = find(y);

  return x == y ? true : false;
}

void getInput(){
  cin>>n>>m;

  for(int i = 1; i <= n; i++)parent[i] = i;

  for(int i = 0; i < m; i++){
    int a,b,c;
    cin>>a>>b>>c;
    v.push_back({c,a,b});
  }
  sort(v.begin(), v.end());
}

int kruskal(){
  for(const auto& edge : v){
    int c = get<0>(edge);
    int a = get<1>(edge);
    int b = get<2>(edge);

    if(!UF(a,b)){
      unite(a,b);
      ans += c;
      cout<<a<<"\t"<<b<<"\t";
    }
  }
  return ans;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  getInput();
  cout<<kruskal();
}