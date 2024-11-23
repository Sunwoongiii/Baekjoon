#include <iostream>
#include <vector>
using namespace std;

int n;
vector<pair<int,int>>v;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin>>n;
  for(int i = 0; i < n;i++){
    int x;
    cin>>x;
    v.push_back({x,i});
  }

  for(int i = 0; i < n; i++){
    int temp = v[i].first;
    int idx = v[i].second;
    int sum = 0;

    if(temp == 0)continue;

    for(int j = i+1; j < n; j++){
      if(temp >= v[j].first){
        sum += v[j].first;
        v[j].first = 0;
      }
      else break;
    }
    v[i].first += sum;
  }

  int cnt = 0;
  for(pair num : v){
    cout<<num.first<<' ';
  }
  // cout<<cnt<<'\n';
}