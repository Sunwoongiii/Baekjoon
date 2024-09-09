#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#define MAXSIZE 100000+1

using namespace std;

int n,k;
bool visited[100001] = {false};
priority_queue<pair<int,int>, vector<pair<int,int>>,greater<pair<int,int>>>pq;
int route[100001] = {-1};
vector<int> ans;

int dijkstra(){
  pq.push({0,n});
  visited[n] = true;

  while(!pq.empty()){
    int value = pq.top().first;
    int node = pq.top().second;
    pq.pop();

    if(node == k){
      return value;
    }
    if(node * 2 < MAXSIZE && !visited[node*2]){
      pq.push({value + 1, node*2});
      visited[node*2] = true;
      route[node*2] = node;
    }
    if(node + 1 < MAXSIZE && !visited[node+1]){
      pq.push({value + 1, node +1});
      visited[node+1] = true;
      route[node+1] = node;
    }
    if(node -1 >= 0 && !visited[node-1]){
      pq.push({value+1, node-1});
      visited[node-1] = true;
      route[node-1] = node;
    }
  }
  return -1;
}

void checkRoute(int node){
  if(node == n){
    cout<<n<<" ";
    return;
  }
  checkRoute(route[node]);
  cout<<node<<" ";
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin>>n>>k;

  cout<<dijkstra()<<"\n";
  checkRoute(k);
}