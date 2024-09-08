#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <math.h>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <sstream>

using namespace std;
using ll = long long;



int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  
  int n;
  int sum = 0;
  cin>>n;
  vector<int>v(n);

  for(int i = 0; i < n; i++){
    int a;
    cin>>a;
    v.push_back(a);
    sum += a;
  }
  cout<<round()


}