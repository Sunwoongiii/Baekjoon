#include <iostream>
#include <deque>
using namespace std;

int n;
deque<int>dq;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin>>n;
  while(n--){
    string command;
    int x;
    cin>>command;

    if(command == "push_front"){
      cin>>x;
      dq.push_front(x);
    }

    else if(command == "push_back"){
      cin>>x;
      dq.push_back(x);
    }

    else if(command == "pop_front"){
      if(dq.empty()){
        cout<<-1<<'\n';
      }
      else{
        x = dq.front();
        cout<<x<<'\n';
        dq.pop_front();
      }
    }

    else if(command == "pop_back"){
      if(dq.empty()){
        cout<<-1<<'\n';
      }
      else{
        x = dq.back();
        cout<<x<<'\n';
        dq.pop_back();
      }
    }

    else if(command == "size"){
      x = dq.size();
      cout<<x<<'\n';
    }

    else if(command == "empty"){
      if(dq.empty())cout<<1<<'\n';
      else cout<<0<<'\n';
    }

    else if(command == "front"){
      if(dq.empty())cout<<-1<<'\n';
      else cout<<dq.front()<<'\n';
    }

    else{
      if(dq.empty())cout<<-1<<'\n';
      else cout<<dq.back()<<'\n';
    }
  }
}