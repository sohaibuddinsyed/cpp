#include <iostream>
using namespace std;

// same as a class except default access is public
class Circle {
  public:
    static double radius;
    int a = 10;

    // static member function
    static double circum() {
        return 2 * Circle::radius * 3.14159265;
    }
};

// static member initialization - always outside class
double Circle :: radius = 10;

int main () {
    Circle foo;

    // obj.<static member>
    cout << "foo's circumference: " << foo.circum()  << '\n';
    // class_name :: <static member>
    cout << "foo's circumference: " << Circle::circum() << '\n';
    cout << Circle::radius << endl;
    cout << foo.a << endl;

    return 0;
}