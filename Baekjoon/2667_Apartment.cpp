#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <math.h>

using namespace std;

int n, cnt = 0;
char map[30][30];
bool visited[30][30] = {false};
queue<pair<int, int>>q;
vector<int> complex_size;
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

int bfs(int a, int b){
    int size = 0;
    q.push({a,b});
    visited[a][b] = true;

    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        size++;

        for(int i = 0; i<4; i++){
            int nx = x+dx[i];
            int ny = y+dy[i];

            if(nx >= n || ny >= n || nx < 0 || ny < 0) continue;
            if(visited[nx][ny]) continue;
            if(map[nx][ny] == '0') continue;

            q.push({nx, ny});
            visited[nx][ny] = true;
        }
    }
    return size;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin>>n;

    for(int i = 0; i<n; i++){
        for(int j = 0; j < n; j++){
            cin>>map[i][j];
        }
    }

    for(int i = 0; i<n; i++){
        for(int j = 0; j < n; j++){
            if(map[i][j] == '1' && !visited[i][j]){
                int complex = bfs(i, j);
                complex_size.push_back(complex);
                cnt++;
            }
        }
    }
    cout<<cnt<<"\n";

    sort(complex_size.begin(), complex_size.end());

    for(int i = 0; i < complex_size.size(); i++){
        cout<<complex_size[i]<<"\n";
    }
}