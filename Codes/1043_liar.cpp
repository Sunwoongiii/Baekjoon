#include <iostream>
#include <vector>
using namespace std;

int parent[55];

int find(int x){
  if(parent[x] == x)return x;
  return parent[x] = find(parent[x]);
}

void unite(int a, int b){
  a = find(a);
  b = find(b);
  if(a != b) parent[b] = a;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int n,m,t;
  cin>>n>>m>>t;
  
  vector<int> truth;
  for(int i = 1; i <= n; i++) parent[i] = i;
  for(int i = 0; i < t; i++){
    int x;
    cin>>x;
    truth.push_back(x);
  }
  vector<vector<int>>party(m);
  for(int i = 0; i < m; i++){
    int cnt;
    cin>>cnt;
    party[i].resize(cnt);
    for(int j = 0; j < cnt; j++)cin>>party[i][j];
    for(int j = 1; j < cnt; j++)unite(party[i][0], party[i][j]);
  }

  vector<int>truthRoot;
  for(int x : truth) truthRoot.push_back(find(x));

  int ans = 0; 
  for(int i = 0; i < m; i++){
    bool canLie = true;
    for(int person : party[i]){
      for(int root : truthRoot){
        if(find(person) == root){
          canLie = false;
          break;
        }
      }
      if(!canLie)break;
    }
    if(canLie)ans++;
  }
  cout<<ans;
}