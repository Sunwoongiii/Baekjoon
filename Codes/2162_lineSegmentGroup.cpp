#include <iostream>
#include <algorithm>
using namespace std;

int n;
vector<int>parent, groupSize;

class Point{
public:
  int x,y;
};

class Segment{
public:
  Point a,b;
};

int ccw(Point a, Point b, Point c){
  int cross = (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
  if(cross > 0)return 1; //반시계 방향
  else if(cross < 0)return -1; // 시계 방향
  else return 0; //일직선상
}

bool isIntersect(Point a, Point b, Point c, Point d){
  int ab_cd = ccw(a,b,c) * ccw(a,b,d);
  int cd_ab = ccw(c,d,a) * ccw(c,d,b);

  if(ab_cd <= 0 && cd_ab <= 0){
    if(ab_cd == 0 && cd_ab == 0){
      if(min(a.x, b.x) <= max(c.x, d.x) && min(c.x, d.x) <= max(a.x, b.x) && min(a.y, b.y) <= max(c.y, d.y) && min(c.y, d.y) <= max(a.y, b.y))return true;
      return false;
    }
    return true;
  }
  return false;
}

int find(int x){
  if(parent[x] == x) return x;
  return parent[x] = find(parent[x]);
}

void UnionFind(int x, int y){
  int rootX = find(x);
  int rootY = find(y);
  if(rootX != rootY){
    parent[rootY] = rootX;
    groupSize[rootX] += groupSize[rootY];
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin>>n;
  vector<Segment>segments(n);
  parent.resize(n);
  groupSize.resize(n,1);

  for(int i = 0; i < n; i++)parent[i] = i;

  for(int i = 0; i < n; i++){
    cin>>segments[i].a.x>>segments[i].a.y>>segments[i].b.x>>segments[i].b.y;
  }
  
  for(int i = 0; i < n; i++){
    for(int j = i+1; j < n; j++){
      if(isIntersect(segments[i].a, segments[i].b, segments[j].a, segments[j].b)){
        UnionFind(i,j);
      }
    }
  }

  int groupCnt = 0;
  int maxSize = 0;
  vector<int>groupCntTracker(n,0);

  for(int i = 0; i < n; i++){
    int root = find(i);
    if(groupCntTracker[root] == 0)groupCnt++;
    groupCntTracker[root] = groupSize[root];
    maxSize = max(maxSize, groupSize[root]);
  }

  cout<<groupCnt<<'\n'<<maxSize;
}