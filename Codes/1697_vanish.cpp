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
#define MAX_SIZE 100000+1

int n,k;
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
bool visited[MAX_SIZE];

int dijkstra(){
  pq.push({0,n});
  visited[n] = true;
  while(!pq.empty()){
    int value = pq.top().first;
    int node = pq.top().second;
    pq.pop();

    if(node == k) return value;

    if(node * 2 < MAX_SIZE && !visited[node*2]){
      pq.push({value+1, node*2});
      visited[node*2] = true;
    }

    if(node + 1 < MAX_SIZE && !visited[node + 1]){
      pq.push({value+1, node+1});
      visited[node+1] = true;
    }

    if(node - 1 >= 0 && !visited[node-1]){
      pq.push({value+1, node-1});
      visited[node-1] = true;
    }
  }
  return -1;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin>>n>>k;
  cout<<dijkstra();
}