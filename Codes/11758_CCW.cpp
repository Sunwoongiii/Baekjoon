#include <iostream>
#include <algorithm>
using namespace std;

class Point{
public:
  int x,y;
};

int CCW(Point& a, Point& b, Point& c){
  int corss = (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);

  if(corss > 0)return 1;
  else if(corss < 0) return -1;
  else return 0;
}

void sol(){
  Point a,b,c;
  cin>>a.x>>a.y>>b.x>>b.y>>c.x>>c.y;
  cout<<CCW(a,b,c);
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  sol();
}