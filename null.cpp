#include <iostream>
using namespace std;

class A {
public:
    int val;
    A() = default;
    A(int v): val(v) {}
};

int* func(int a) {
    int *newP = new int(a);
    return newP;
}

int main() {

    int *p = func(10);
    cout << *p << endl;

    // A obj(10);
    // A *p1 = &obj;
    // cout << p1 -> val << endl;

    // p1 = nullptr;
    // cout << p1 -> val << endl;

    return 0;
}