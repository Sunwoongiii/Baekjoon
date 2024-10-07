#include <iostream>
using namespace std;

int n;
int paper[130][130];
int white = 0, blue = 0;

bool isOneColor(int x, int y, int size){
  int color = paper[x][y];
  for(int i = x; i < x+size; i++){
    for(int j =y ; j < y+size; j++){
      if(paper[i][j] != color) return false;
    }
  }
  return true;
}

void countColor(int x, int y, int size){
  if(isOneColor(x,y,size)){
    if(paper[x][y] == 0) white++;
    else blue++;
  }
  else{
    int newSize = size/2;
    countColor(x,y,newSize);
    countColor(x+newSize,y,newSize);
    countColor(x,y+newSize,newSize);
    countColor(x+newSize,y+newSize,newSize);
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin>>n;
  for(int i =0 ; i< n;i++){
    for(int j=0;j<n;j++){
      cin>>paper[i][j];
    }
  }
  countColor(0,0,n);
  cout<<white<<"\n"<<blue<<"\n";
  return 00;
}