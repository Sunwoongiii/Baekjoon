#include <iostream>
#include <queue>
#include <vector>
#include <tuple>
using namespace std;

char miro[55][55]; /*1: 출구, 0: 입구, #: 벽, 소문자: 키, 대문자: 잠긴 문*/
bool visited[55][55][1 << 6];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
int n, m;

struct Point {
  int x, y, dist, keys;
};

queue<Point> q;

void getInput() {
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> miro[i][j];
      if (miro[i][j] == '0') {
        q.push({i, j, 0, 0});
        visited[i][j][0] = true; 
      }
    }
  }
}

bool isInside(int x, int y) {
  return x >= 0 && y >= 0 && x < n && y < m;
}

int bfs() {
  while (!q.empty()) {
    Point cur = q.front();
    q.pop();

    for (int i = 0; i < 4; i++) {
      int nx = cur.x + dx[i];
      int ny = cur.y + dy[i];
      int keys = cur.keys;

      if (!isInside(nx, ny)) continue;
      if (visited[nx][ny][keys]) continue; 
      char cell = miro[nx][ny];

      if (cell == '#') continue; 
      if (cell == '1') return cur.dist + 1; 

      if (cell >= 'A' && cell <= 'Z') {
        if (!(keys & (1 << (cell - 'A')))) continue;
      }

      if (cell >= 'a' && cell <= 'z') {
        // 키 발견 (키 상태 갱신)
        keys |= (1 << (cell - 'a'));
      }

      if (!visited[nx][ny][keys]) {
        visited[nx][ny][keys] = true;
        q.push({nx, ny, cur.dist + 1, keys});
      }
    }
  }

  return -1;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  getInput();
  cout << bfs();
}
