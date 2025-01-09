#include <iostream>

using namespace std;

struct Point {
    long long x, y;
    bool operator<=(Point const &other) {
        if (x == other.x) {
            return y <= other.y;
        }
        return x <= other.x;
    }
};

struct Segment {
    Point start, end;
};

Segment segments[2];

int crossProduct(const Point &a, const Point &b, const Point &c) {
    long long result = (a.x * b.y + b.x * c.y + c.x * a.y) - 
                       (b.x * a.y + c.x * b.y + a.x * c.y);

    if (result > 0) return 1;
    else if (result < 0) return -1;
    else return 0;
}

bool doSegmentsIntersect(Segment &s1, Segment &s2) {
    int ccw1, ccw2;

    ccw1 = crossProduct(s1.start, s1.end, s2.start) * crossProduct(s1.start, s1.end, s2.end);
    ccw2 = crossProduct(s2.start, s2.end, s1.start) * crossProduct(s2.start, s2.end, s1.end);

    if (ccw1 <= 0 && ccw2 <= 0) {
        if (ccw1 == 0 && ccw2 == 0) {
            if (s1.end <= s1.start) swap(s1.start, s1.end);
            if (s2.end <= s2.start) swap(s2.start, s2.end);

            return s1.start <= s2.end && s2.start <= s1.end;
        }
        else return true;
    }
    else return false;
}

void solve() {
    if (doSegmentsIntersect(segments[0], segments[1])) {
        cout << 1;
    }
    else cout << 0;
}

void input() {
    long long x1, x2, y1, y2;
    Point p1, p2;
    for (int i = 0; i < 2; i++) {
        cin >> p1.x >> p1.y >> p2.x >> p2.y;
        segments[i].start = p1;
        segments[i].end = p2;
    }
}

int main() {
    input();
    solve();

    return 0;
}
