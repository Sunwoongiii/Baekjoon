#include <iostream>
using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int n,T;
  int start, end;
  int x,y,r,x1,x2,y1,y2;

  cin>>T;
  while(T--){
    cin>>x1>>y1>>x2>>y2;
    cin>>n;

    start = 0;
    end = 0;

    while(n--){
      cin>>x>>y>>r;

      if((x-x1) * (x-x1) + (y-y1) * (y-y1) < r*r){
        if((x-x2) * (x-x2) + (y-y2) * (y-y2) > r*r)end++;
      }
      if((x-x1) * (x-x1) + (y-y1) * (y-y1) > r*r){
        if((x-x2) * (x-x2) + (y-y2) * (y-y2) < r*r)start++;
      }
    }
    cout<<start + end<<'\n';
  }
}