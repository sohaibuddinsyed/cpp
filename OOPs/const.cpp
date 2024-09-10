#include <iostream>
using namespace std;

class Const {
    // mutable storage class allows const member functions to mutate values
    mutable int m;
    int n;
public:
    Const(): m(0) {}
    Const(int a): m(a) {}
    int get() const {
        m += 1;
        return m;
    }
    int get() {
        return m;
    }

};
int main() {
    // const get() is called
    const Const c(1);
    cout << c.get() << endl;

    // Non-const get() is called
    Const c2(10);
    cout << c2.get() << endl;
}