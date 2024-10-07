#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

char miro[110][110];
bool visited[110][110];
int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};
int w,h;
queue<pair<int,int>>q;

class Point{
  public:
    int x;
    int y;
    int mirror;
    int direction;
    Point(int x, int y, int mirror, int direction): x(x),y(y),mirror(mirror),direction(direction){}
};

Point p1(-1,-1,0,0);
Point p2(-1,-1,0,0);

void getInput(){
  int cnt = 0;
  cin>>h>>w;
  for(int i = 0; i < h; i++){
    for(int j = 0; j < w; j++){
      cin>>miro[i][j];
      if(miro[i][j] == 'C'){
        if(cnt == 0){
          p1.x = i;
          p1.y = j;
          cnt++;
        }
        else{
          p2.x = i;
          p2.y = j;
        }
      }
    }
  }
}

bool isInside(int a, int b){
  return(a>=0&&b>=0&&a<h&&b<w);
}

int bfs(){
  q.push({p1.x,p1.y});

  while(!q.empty()){
    int x = q.front().first;
    int y = q.front().second;
    q.pop();


  }
}