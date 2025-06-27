#include <iostream>
using namespace std;

int C,R,K,x,y;
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
bool miro[1010][1010];

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin>>R>>C>>K;
  if(C*R < K){
    cout<<0;
    return 0;
  }
  else if(K==1){
    cout<<1<<' '<<1;
    return 0;
  }
  else{
    x = 1, y = 1;
    int n = 0, ans = 1;
    miro[1][1] = true;

    while(true){
      int nx = x + dx[n];
      int ny = y + dy[n];
      if(nx > R || nx <= 0 || ny > C || ny <= 0 || miro[nx][ny]) n = (n+1) % 4;
      x += dx[n];
      y += dy[n];
      miro[x][y] = true;
      ans++;
      if(ans == K) break;
    }
  }
  cout<<x<<' '<<y;
}