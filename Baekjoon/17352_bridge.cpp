#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <math.h>

using namespace std;
int n;
int parent[300003];
bool visited[300003];
vector<int>v[300003];

int find(int x){
  if(parent[x] == x){
    return x;
  }
  return parent[x] = find(parent[x]);
}

bool isConnect(int x, int y){
  if(find(x) == find(y)) return true;//이어져있다
  return false;//이어져 있지 않다
}

void bridge(int x, int y){

}//이어야 하는데 시발 어떻게 하지?

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin>>n;
  for(int i= 0; i < n; i++){
    parent[i] = i;//부모 = 자기자신 설정
  }

  for(int i = 0; i < n-2; i++){
    int a, b;
    v[a].push_back(b);
    v[b].push_back(a);

  }//a b를 이어야한다 how??????????????????????????????????
}