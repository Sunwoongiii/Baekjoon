#include <algorithm>
#include <iostream>
using namespace std;

int N;
int rope[100001];
int cur;
int maxi;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin>>N;
  for(int i = 0; i < N; i++)cin>>rope[i];

  sort(rope, rope+N);
  maxi = rope[N-1];

  for(int i = N-1; i >= 0; i--){
    cur = rope[i] * (N-i);
    if(maxi < cur)maxi = cur;
  }

  cout<<maxi;
  return 0;
}