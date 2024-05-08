#include <iostream>
using namespace std;

class Base {
protected:
    int base;
public:
    Base() = default;
    Base(int b): base(b) {
        cout << "Base init\n";
    }
    ~Base() {
        cout << "Base destroyed\n";
    }
};

class Derived: public Base {
public:
    Derived() = default;
    Derived(int d): Base(d) {
        cout << "Derived init\n";
    }
    ~Derived() {
        cout << "Derived destroyed\n";
    }
};

int main() {
    Derived d(10);
}