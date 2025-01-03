#include <iostream>
#include <vector>
using namespace std;

int N,r,c;
int ans;

void Z(int y, int x, int size){
  if(y == r && x == c){
    cout<<ans<<'\n';
    return;
  }

  if(r < y + size && r >= y && c < x + size && c >= x){
    Z(y,x,size/2);
    Z(y,x+size/2, size/2);
    Z(y+size/2, x, size/2);
    Z(y+size/2, x + size/2, size/2);
  }
  else{
    ans += size * size;
  }
}

int main(){
  cin>>N>>r>>c;
  Z(0,0,(1<<N));
  return 0;
}