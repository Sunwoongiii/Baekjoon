#include <iostream>
#include <algorithm>
using namespace std;

int minDp[3] = {0,0,0};
int maxDp[3] = {0,0,0};
int N;
int miro[100001][3];

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin>>N;
  for(int i = 0; i < N; i++){
    for(int j = 0; j < 3; j++){
      cin>>miro[i][j];
    }
  }

  minDp[0] = miro[0][0];
  minDp[1] = miro[0][1];
  minDp[2] = miro[0][2];
  maxDp[0] = miro[0][0];
  maxDp[1] = miro[0][1];
  maxDp[2] = miro[0][2];

  for(int i = 1; i < N; i++){
    int minTemp[3] = {0,0,0};
    int maxTemp[3] = {0,0,0};
    minTemp[0] = min(minDp[0],minDp[1]) + miro[i][0];
    minTemp[1] = min(minDp[0],min(minDp[1],minDp[2])) + miro[i][1];
    minTemp[2] = min(minDp[1],minDp[2]) + miro[i][2];

    maxTemp[0] = max(maxDp[0],maxDp[1]) + miro[i][0];
    maxTemp[1] = max(maxDp[0],max(maxDp[1],maxDp[2])) + miro[i][1];
    maxTemp[2] = max(maxDp[1],maxDp[2]) + miro[i][2];

    for(int j = 0; j < 3; j++){
      minDp[j] = minTemp[j];
      maxDp[j] = maxTemp[j];
    }
  }
  cout<<max(maxDp[0],max(maxDp[1],maxDp[2]))<<" "<<min(minDp[0],min(minDp[1],minDp[2]));
}