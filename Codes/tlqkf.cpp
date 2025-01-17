// #include <iostream>
// #include <queue>
// using namespace std;

// int m,n,h;
// int graph[100][100][100];
// bool visited[100][100][100];

// int dx[6] = {1,-1,0,0,0,0};
// int dy[6] = {0,0,1,-1,0,0};
// int dz[6] = {0,0,0,0,1,-1};

// struct Tuple
// {
//     int x,y,z,cnt;
//     Tuple(int a,int b,int c,int d)
//     {
//         x=a; y=b; z=c; cnt=d;
//     }
// };

// int BFS(int x,int y, int z)
// {
//     int cnt = 0;
//     int check = 0;
//     int cx,cy,cz;
//     queue<Tuple> q;
//     q.push(Tuple(x,y,z,cnt));
//     while(!q.empty())
//     {
//         cx = q.front().x;
//         cy = q.front().y;
//         cz = q.front().z;
//         cnt = q.front().cnt;

//         q.pop();

//         if (visited[cx][cy][cz])
//             continue;

//         if (graph[cx][cy][cz]==0)
//             graph[cx][cy][cz] = 1;
        
//         visited[cx][cy][cz] = true;

//         for (int i=0; i<6; i++)
//         {
//             int dcx = cx+dx[i];
//             int dcy = cy+dy[i];
//             int dcz = cz+dz[i];

//             if (dcx<0||dcx>m-1||dcy<0||dcy>n-1||dcz<0||dcz>h-1||visited[dcx][dcy][dcz]||graph[dcx][dcy][dcz]==-1)
//                 continue;
//             else if (graph[dcx][dcy][dcz]==1)
//                 q.push(Tuple(dcx,dcy,dcz,cnt));
//             else
//                 q.push(Tuple(dcx,dcy,dcz,cnt+1));
//         }
//     }
//     return cnt;
// }

// int main()
// {
//     cin >> m >> n >> h;
//     int start[3];
//     int check = 0;
//     for (int k=0; k<h; k++)
//     {
//         for (int j=0; j<n; j++)
//         {
//             for (int i=0; i<m; i++)
//             {
//                 cin >> graph[i][j][k];
//                 if (graph[i][j][k]==1)
//                 {
//                     start[0] = i;
//                     start[1] = j;
//                     start[2] = k;
//                 }
//                 else
//                 {
//                     if (graph[i][j][k]==0)
//                         check++;
//                 }    
//             }
//         }
//     }
    
//     if (check==0)
//     {
//         cout << 0;
//         return 0;
//     }

//     int result = BFS(start[0],start[1],start[2]);

//     for (int k=0; k<h; k++)
//     {
//         for (int j=0; j<n; j++)
//         {
//             for (int i=0; i<m; i++)
//             {
//                 if(graph[i][j][k] == 0)
//                 {
//                     cout << -1;
//                     return 0;
//                 }
//             }
//         }
//     }
//     cout << result;
// }

#include <iostream>
#include <tuple>
#include <algorithm>
#include <queue>
using namespace std;

int n,m,h;
int miro[101][101][101];
int ans[101][101][101];
queue<tuple<int,int,int>>q;
int dx[6] = {0,0,0,0,1,-1};
int dy[6] = {0,0,-1,1,0,0};
int dz[6] = {1,-1,0,0,0,0};

void getInput(){
  cin>>m>>n>>h;
  for(int k = 0; k < h; k++){
    for(int i = 0; i < n; i++){
      for(int j = 0; j < m; j++){
        cin>>miro[k][i][j];
        ans[k][i][j] = miro[k][i][j];
        if(miro[k][i][j] == 1){
          q.push({i,j,k});
        }
      }
    }
  }
}

bool isInside(int a, int b, int c){
  return (a >= 0 && b >= 0 && c >= 0 && a < n && b < m && c < h);
}

void bfs(){
  while(!q.empty()){
    int x,y,z;
    tie(x,y,z) = q.front();
    q.pop();

    for(int i = 0; i < 6; i++){
      int nx = x + dx[i];
      int ny = y + dy[i];
      int nz = z + dz[i];

      if(isInside(nx,ny,nz) && miro[nz][nx][ny] == 0){
        miro[nz][nx][ny] = 1;
        ans[nz][nx][ny] = ans[z][x][y] + 1;
        q.push({nx,ny,nz});
      }
    }
  }
}

void sol(){
  getInput();
  bfs();
  int day = 0;

  for(int k = 0; k < h; k++){
    for(int i = 0; i < n; i++){
      for(int j = 0; j < m; j++){
        if(ans[k][i][j] == 0){
          cout<<-1;
          return;
        }
        day = max(ans[k][i][j], day);
      }
    }
  }
  cout<<day-1;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  sol();
}