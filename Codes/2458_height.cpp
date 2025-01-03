#include <iostream>
#include <algorithm>

using namespace std;

int n,m;
int miro[505][505]; // i < j;
int inf = 2e9;

void initialize(){
  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= n; j++){
      if(miro[i][j] == 0) miro[i][j] = 0;
      else miro[i][j] = inf;
    }
  }
}

void inputNode(){
  while(m--){
    int a,b;
    cin>>a>>b;
    miro[a][b]
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin>>n>>m;

}