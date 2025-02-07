#include <iostream>
using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int line = 1;
  int x;
  cin>>x;

  while(x - line > 0){
    x -= line;
    line++;
  }

  if(line % 2) cout<<line+1-x<<'/'<<x;
  else cout<<x <<'/'<<line+1-x;
}