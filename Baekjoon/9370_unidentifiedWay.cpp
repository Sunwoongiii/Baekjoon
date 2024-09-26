#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int T,n,m,t,s,g,h,x;
vector<pair<int,int>>v[2002];
vector<int>candidate;
vector<int>answer;
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
int dist_s[2002],dist_g[2002],dist_h[2002];
const int INF = 2e9;

void dijkstra(int start, int dist[]){
  fill(dist, dist+n+1, INF);
  dist[start] = 0;
  pq.push({0,start});

  while(!pq.empty()){
    int value = pq.top().first;
    int node=  pq.top().second;
    pq.pop();

    if(dist[node] < value) continue;
    for(int i = 0; i < v[node].size(); i++){
      int cost = v[node][i].first;
      int next=  v[node][i].second;

      if(dist[next] > dist[node] + cost){
        dist[next] = dist[node]+cost;
        pq.push({dist[next], next});
      }
    }
  }
}

void getInput(){
  cin>>n>>m>>t>>s>>g>>h;
  for(int i = 1; i <= n; i++) v[i].clear();
  for(int i = 0; i < m; i++){
    int a,b,d;
    cin>>a>>b>>d;
    v[a].push_back({d,b});
    v[b].push_back({d,a});
  }
  candidate.clear();
  for(int i = 0; i < t; i++){
    cin>>x;
    candidate.push_back(x);
  }
}

void findCandidates(){
  answer.clear();

  dijkstra(s,dist_s);
  dijkstra(g,dist_g);
  dijkstra(h,dist_h);

  for(int end : candidate){
    int directway = dist_s[end];
    int sghe = dist_s[g] + dist_g[h] + dist_h[end];
    int shge = dist_s[h] + dist_h[g] + dist_g[end];

    if(directway == min(sghe, shge))answer.push_back(end);
  }
}

void printAnswer(){
  if(answer.empty()) cout<<"ERROR";
  else{
    sort(answer.begin(), answer.end());
    for(int des : answer) cout<<des<<" ";
  }
  cout<<"\n";
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin>>T;
  while(T--){
    getInput();
    findCandidates();
    printAnswer();
  }
  return 0;
}