#include <iostream>
#include <queue>
#include <vector>
using namespace std;
priority_queue<int>pq;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int n,x;
  cin>>n;
  for(int i = 0; i < n; i++){
    cin>>x;
    if(x == 0){
      if(pq.empty()) cout<<0<<"\n";
      else{
        cout<<pq.top()<<"\n";
        pq.pop();
      }
    }
    else pq.push(x);
  }
}