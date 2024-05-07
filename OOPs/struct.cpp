#include <iostream>
using namespace std;

// same as a class except default access is public
struct Circle {
    double radius;
  public:
    // member initialization
    Circle(double r) : radius(r) { }
    double circum() {return 2*radius*3.14159265;}
};

int main () {
  Circle foo (10.0);   // functional form
  Circle bar = 20.0;   // assignment init.
  Circle baz {30.0};   // uniform init.
  Circle qux = {40.0}; // POD-like

  cout << "foo's circumference: " << foo.circum() << '\n';
  cout << foo.radius << endl;
  return 0;
}