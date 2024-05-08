#include <iostream>
using namespace std;

class Circle {
    double radius;
  public:
    Circle(): radius(0.0) {};
    // member initialization
    Circle(double r) : radius(r) { }
    // Copy constructor
    Circle(Circle &c): radius(c.radius) {
        cout << "Copy constructor called" << endl;
    }
    // copy assignment operator
    Circle& operator=(Circle &c) {
        cout << "Copy assignment called" << endl;
        radius = c.radius;
        return *this;
    }
    // Move constructor 
    Circle(Circle&& c): radius(c.radius) {
        cout << "Move constructor called" << endl;
    }
    // Move assignment
    Circle& operator=(Circle &&c) {
        cout << "Move assignment called" << endl;
        radius = c.radius;
        c.radius = 0;

        return *this;
    }

    double circum() {return 2*radius*3.14159265;}
};

Circle getObj() {
    Circle c(40);
    return c;
}

int main () {
    Circle foo (10.0);   // functional form
    Circle bar = 20.0;   // assignment init. (implicit conversion using ctor; disabled on explicit)
    Circle baz {30.0};   // uniform init.
    Circle qux = {40.0}; // POD-like
    cout << "foo's circumference: " << foo.circum() << '\n';

    // Both copy constructors
    Circle c1(bar);
    cout << "c1's circumference: " << c1.circum() << '\n';
    Circle c2 = c1;
    cout << "c2's circumference: " << c2.circum() << '\n';

    // object already initialized: copy assignment called 
    foo = c1;
    cout << "foo's circumference: " << foo.circum() << '\n';

    // Compilers already optimize many cases that formally require a move-construction call 
    // in what is known as Return Value Optimization. Most notably, when the value returned by 
    // a function is used to initialize an object. In these cases, the move constructor may 
    // actually never get called. Thus, we use std::move() or explicit cast to rval ref to demonstrate.
    Circle c3 = (Circle &&) getObj();
    cout << "c3's circumference: " << c3.circum() << '\n';

    c3 = move(c1);
    return 0;
}