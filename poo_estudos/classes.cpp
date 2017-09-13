#include <iostream>

using namespace std;

class Point{
private:
  float x;
  float y;
public:
  void setX(float _x){
    x = _x;
  }
  void setY(float _y){
    y = _y;
  }
  float getX(){
    return x;
  }
  float getY(){
    return y;
  }
  void print(){
    cout << "(" << x << ", "<< y <<")" << endl;
  }
};

int main(){
  Point p1;
  p1.setX(1);
  p1.setY(2);
  p1.print();

  return 0;
}
