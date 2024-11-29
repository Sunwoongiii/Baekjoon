#include <iostream>
using namespace std;

class Circle{
  int radius;

public:
  Circle(int radius = 0){this->radius = radius;}
  void show()cout<<"Circle's radius = "<<radius<<endl;

  friend
}

int main(){
  Circle a(5),b;
  b = ++a;
  a.show();
  b.show();
  b = a++;
  a.show();
  b.show();
}