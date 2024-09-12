#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>

using namespace std;
//queue에 들어가야할 자료: x, y

int n, shark = 2,cnt;
int miro[22][22];
bool visited[22][22];
queue<pair<int,int>>q;
vector<pair<int,int>>dist;//거리, 덩치

bool isInsied(int x, int y){
  return (x >= 0 && y >= 0 && x < n && y < n);
}

int bfs();

void getDist(int sX, int sY, int pX, int pY){
  int targetDist = abs(sX-pX) + abs(sY-pY);
  dist.push_back
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

}