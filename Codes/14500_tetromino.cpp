#include <iostream>
using namespace std;

int n, m, ans;
int miro[505][505];
int visited[505][505];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

bool isInside(int a, int b) {
  return (a >= 1 && b >= 1 && a <= n && b <= m);
}

void dfs(int x, int y, int cnt, int val) {
  if (cnt == 4) {
    ans = max(ans, val);
    return;
  }

  for (int i = 0; i < 4; i++) {
    int nx = x + dx[i];
    int ny = y + dy[i];

    if (isInside(nx, ny) && !visited[nx][ny]) {
      visited[nx][ny] = 1;
      dfs(nx, ny, cnt + 1, val + miro[nx][ny]);
      visited[nx][ny] = 0;
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> miro[i][j];
    }
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      visited[i][j] = 1;
      dfs(i, j, 1, miro[i][j]);
      visited[i][j] = 0;
    }
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      int t = miro[i][j], mini = 10001, cnt = 0;
      for (int k = 0; k < 4; k++) {
        int nx = i + dx[k];
        int ny = j + dy[k];

        if (isInside(nx, ny)) {
          mini = min(mini, miro[nx][ny]);
          t += miro[nx][ny];
          cnt++;
        }
      }
      if (cnt == 4) t -= mini;
      ans = max(ans, t);
    }
  }
  cout << ans;
}