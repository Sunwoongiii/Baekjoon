#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>

using namespace std;

int miro[101][101];
bool isVisited[101][101];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};
int n;
queue<pair<int, int>> q;
vector<int> safeSize;

bool isInside(int a, int b) {
    return (a >= 0 && b >= 0 && a < n && b < n);
}

void reset() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            isVisited[i][j] = false;
        }
    }
    while (!q.empty()) q.pop();
}

void bfs(int a, int b, int h) {
    q.push({a, b});
    isVisited[a][b] = true;

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (isInside(nx, ny) && !isVisited[nx][ny] && miro[nx][ny] > h) {
                q.push({nx, ny});
                isVisited[nx][ny] = true;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    int tempHight = -1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> miro[i][j];
            if (miro[i][j] > tempHight) {
                tempHight = miro[i][j];
            }
        }
    }
    int hight = tempHight;

    for (int i = 0; i <= hight; i++) {
        int cnt = 0;
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                if (!isVisited[j][k] && miro[j][k] > i) {
                    bfs(j, k, i);
                    cnt++;
                }
            }
        }
        safeSize.push_back(cnt);
        reset();
    }

    sort(safeSize.begin(), safeSize.end());

    if (safeSize.back() == 0) {
        cout << 1;
    } else {
        cout << safeSize.back();
    }

    return 0;
}
