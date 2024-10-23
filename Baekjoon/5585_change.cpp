#include <vector>
#include <iostream>
using namespace std;

int cash, cnt=0;

int main(){
  cin>>cash;
  int change = 1000 - cash;

  while(change != 0){
    if(change >= 500){
      change -= 500;
      cnt++;
    }
    else if(change >= 100){
      change -= 100;
      cnt++;
    }
    else if(change >= 50){
      change -= 50;
      cnt++;
    }
    else if(change>=10){
      change-=10;
      cnt++;
    }
    else if(change >= 5){
      change -= 5;
      cnt++;
    }
    else{
      change--;
      cnt++;
    }
  }
  cout<<cnt;
  return 0;
}