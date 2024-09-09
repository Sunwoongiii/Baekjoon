#include <iostream>
#include <algorithm>
#define MAX 201
#define INF 2e9

using namespace std;

int n,m;
int graph[MAX][MAX], answer[MAX][MAX];
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin>>n>>m;
  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= n; j++){
      if(i == j)graph[i][j] = 0;
      else graph[i][j] = INF;
    }
  }

  for(int i = 0; i < m; i++){
    int from, to, dis;
    cin>>from>>to>>dis;
    graph[from][to] = dis;
    graph[to][from] = dis;
    answer[from][to] = to;
    answer[to][from] = from;
  }

  for(int k = 1; k <= n; k++){
    for(int i = 1; i <= n; i++){
      for(int j = 1; j <= n; j++){
        if(graph[i][j] > graph[i][k] + graph[k][j]){
          graph[i][j] = graph[i][k] + graph[k][j];
          answer[i][j] = answer[j][k];
        }
      }
    }
  }

  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= n; j++){
      if(answer[i][j] == 0)cout<<"- ";
      else cout<<answer[i][j]<<" ";
    }
    cout<<"\n";
  }
}