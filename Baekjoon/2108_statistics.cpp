#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

vector<int>nums, modes;
int cnt[8001];
int N, modeCnt;
double sum;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin>>N;
  nums = vector<int>(N);
  modes.reserve(N);

  for(int &num : nums){
    cin>>num;
    sum += num;
    cnt[num+4000]++;
  }
  
  sort(nums.begin(), nums.end());

  for(int i = 0 ; i < 8001; i++){
    if(cnt[i] > modeCnt){
      modes.clear();
      modeCnt = cnt[i];
      modes.push_back(i-4000);
    }
    else if(cnt[i] == modeCnt){
      modes.push_back(i-4000);
    }
  }

  cout<<round(sum/N)+0.0<<"\n";
  cout<<nums[N/2]<<"\n";
  cout<<(modes.size() == 1 ? modes.front() : modes[1])<<"\n";
  cout<<nums.back() - nums.front();
}