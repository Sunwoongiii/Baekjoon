#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int N;
  vector<int>x;
  vector<int>y;
  cin>>N;

  for(int i = 0; i < N; i++){
    int a,b;
    cin>>a>>b;
    x.push_back(a); y.push_back(b);
  }

  sort(x.begin(), x.end());
  sort(y.begin(), y.end());

  int w = x.back() - x.front();
  int h = y.back() - y.front();

  cout<<w*h;
}