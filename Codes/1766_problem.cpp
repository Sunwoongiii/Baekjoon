#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int N, M;
vector<int>v[33000];
vector<int>path;
bool visited[33000];
priority_queue<int,vector<int>,greater<int>>pq;

void getInput(){
  cin>>N>>M;
  for(int i =0 ; i < M; i++){
    int a,b;
    cin>>a>>b;
    v[b].push_back(a);
  }
}

void bfs(){
  pq.push(1);
  visited[1] = true;
  while(!pq.empty()){
    int node = pq.top();
    path.push_back(node);

    if(v[node].size() == 0 && node < N && !visited[node+1]){
      pq.push(++node);
      visited[node] = true;
      path.push_back(node);
    }

    else{
      for(int i = 0; i < v[node].size(); i++){
        int next = v[node].front();
        
      }
    }
  }
}