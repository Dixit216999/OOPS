#include <iostream>
#include <string>

using namespace std;

/*------------------ In this we will study Abstraction in OOPs ------------------*/

class Shape{  //abstract class
public:
  virtual void draw() = 0; //pure virtual function makes this class abstract
};

class Circle : public Shape{
    public:
  void draw() {
      cout << "Drawing Circle" << endl;
  }
};

int main(){
    Circle c;
    c.draw();
    return 0;
}
/*------------------ The above example is of Abstract Class which is a way to achieve Abstraction ------------------*/