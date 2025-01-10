#include <iostream>
#include <algorithm>
using namespace std;

class Point {
public:
  int x, y;
};

int CCW(Point a, Point b, Point c) {
  long long cross = 1LL * (b.x - a.x) * (c.y - a.y) - 1LL * (b.y - a.y) * (c.x - a.x);
  if (cross > 0) return 1;
  else if (cross < 0) return -1;
  else return 0;
}

int isIntersect(Point a, Point b, Point c, Point d) {
  int ab_cd = CCW(a, b, c) * CCW(a, b, d);
  int cd_ab = CCW(c, d, a) * CCW(c, d, b);

  if (ab_cd <= 0 && cd_ab <= 0) {
    if (ab_cd == 0 && cd_ab == 0) {
      bool overlapX = min(a.x, b.x) <= max(c.x, d.x) && min(c.x, d.x) <= max(a.x, b.x);
      bool overlapY = min(a.y, b.y) <= max(c.y, d.y) && min(c.y, d.y) <= max(a.y, b.y);
      return overlapX && overlapY ? 1 : 0;
    }
    return 1;
  }
  return 0;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  Point a, b, c, d;
  cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y >> d.x >> d.y;
  cout << isIntersect(a, b, c, d);
}
