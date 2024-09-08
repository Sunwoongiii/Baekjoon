#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>

using namespace std;

bool baechoo[55][55];
bool visited[55][55];

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int cnt;
int t, m, n, k;
queue<pair<int, int>> q;

void bfs(int a, int b) {
    q.push({a, b});
    visited[a][b] = true;

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= n || ny >= m || nx < 0 || ny < 0) continue;
            if (visited[nx][ny]) continue;
            if (!baechoo[nx][ny]) continue;

            q.push({nx, ny});
            visited[nx][ny] = true;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> t;
    while (t--) {
        cin >> m >> n >> k;

        fill(&baechoo[0][0], &baechoo[0][0] + sizeof(baechoo), false);
        fill(&visited[0][0], &visited[0][0] + sizeof(visited), false);

        for (int i = 0; i < k; i++) {
            int a, b;
            cin >> a >> b;
            baechoo[a][b] = true;
        }
        cnt = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (baechoo[i][j] && !visited[i][j]) {
                    bfs(i, j);
                    cnt++;
                }
            }
        }
        cout << cnt << "\n";
    }
    return 0;
}
