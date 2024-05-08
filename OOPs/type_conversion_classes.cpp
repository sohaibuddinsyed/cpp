#include <iostream>
using namespace std;
class A {

};

class B {
public:
    B() = default;
    // Convert from A
    B(A &a) {
        cout << "Invoked ctor implicitly\n";
    }
    // Convert from A
    B operator=(A &a) {
        cout << "Invoked assignment operator implicitly\n";
        return *this;
    }
    // Convert to A
    explicit operator A() {
        cout << "Invoked type-cast operator implicitly\n";
        return A();
    }
};


int main() {
    A a;
    // Convert from A
    B b = a;
    b = a;
    // Convert to A made explicit
    a = (A) b;

    // C-style explicit type conversions
    B *bb = (B*) new A(); 
    A *aa = (A*) new B(); 

    // Cannot use static_cast since unrelated objects
    A *aaa = reinterpret_cast<A*>(new B()); 
    return 0;
}