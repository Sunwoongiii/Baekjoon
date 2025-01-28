#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
  vector<int>v;
  int check = 0;

  string N;
  cin>>N;

  for(int i = 0; i < N.size(); i++){
    v.push_back(N[i]-'0');
  }

  sort(v.rbegin(), v.rend());

  for(int i = 0; i < N.size(); i++){
    check += v[i];
  }

  if(check %3 != 0) cout<<-1;
  else if(v[v.size()-1] != 0) cout<<-1;
  else for(int x : v)cout<<x;
}