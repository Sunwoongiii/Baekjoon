#include <iostream>
#include <algorithm>
using namespace std;

int miro[505][505];
int n, k;

void getInput() {
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < k; j++) {
      cin >> miro[i][j];
    }
  }
}

int tetromino(int a, int b) {
  int res = 0;

  if (b + 3 < k) res = max(res, miro[a][b] + miro[a][b + 1] + miro[a][b + 2] + miro[a][b + 3]);
  if (a + 3 < n) res = max(res, miro[a][b] + miro[a + 1][b] + miro[a + 2][b] + miro[a + 3][b]);

  if (a + 1 < n && b + 1 < k) res = max(res, miro[a][b] + miro[a][b + 1] + miro[a + 1][b] + miro[a + 1][b + 1]);

  if (a + 2 < n && b + 1 < k) res = max(res, miro[a][b] + miro[a + 1][b] + miro[a + 2][b] + miro[a][b + 1]);
  if (a + 2 < n && b - 1 >= 0) res = max(res, miro[a][b] + miro[a + 1][b] + miro[a + 2][b] + miro[a][b - 1]);
  if (a + 1 < n && b + 2 < k) res = max(res, miro[a][b] + miro[a][b + 1] + miro[a][b + 2] + miro[a + 1][b]);
  if (a + 1 < n && b - 2 >= 0) res = max(res, miro[a][b] + miro[a][b - 1] + miro[a][b - 2] + miro[a + 1][b]);

  if (a + 1 < n && b + 2 < k) res = max(res, miro[a][b] + miro[a][b + 1] + miro[a][b + 2] + miro[a + 1][b + 1]);
  if (a + 2 < n && b + 1 < k) res = max(res, miro[a][b] + miro[a + 1][b] + miro[a + 2][b] + miro[a + 1][b + 1]);
  if (a + 1 < n && b - 1 >= 0 && b + 1 < k) res = max(res, miro[a][b] + miro[a + 1][b] + miro[a][b - 1] + miro[a][b + 1]);
  if (a - 1 >= 0 && b + 2 < k) res = max(res, miro[a][b] + miro[a][b + 1] + miro[a][b + 2] + miro[a - 1][b + 1]);

  return res;
}

void sol() {
  int ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < k; j++) {
      ans = max(ans, tetromino(i, j));
    }
  }
  cout << ans;
}

int main() {
  getInput();
  sol();
  return 0;
}
