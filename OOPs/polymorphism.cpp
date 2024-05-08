#include <iostream>
using namespace std;

class Base {
private:
    int get_private_base () {
        return base;
    }
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
    // inherited in derived
    int get_base () {
        return base;
    }
    // pure virtual function
    virtual int virtual_func() = 0;
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

    // Re-defined in derived w/o virtual, base get_base() is accessed via base ptrs
    // int get_base () {
    //     return base;
    // }

    // Only in derived
    int get_derived () {
        return base;
    }
    int virtual_func() {
        return base;
    }
};

int main() {
    Derived d1(10), d2(20);
    Base *b1 = &d1, *b2 = &d2;

    // base ptr can only access all inherited base class members in derived
    cout << b1 -> get_base() << endl;
    cout << b2 -> get_base() << endl;

    // Error: base ptr has no access to members of derived 
    // cout << b2 -> get_derived() << endl;
    // Error: base ptr has no access to non-inherited members of base in derived 
    // cout << b2 -> get_private_base() << endl;

    // base ptr can ONLY access all inherited base class members in derived
    // unless they are virtual. Then base can access the redefined derived version of virtual func
    cout << b1 -> virtual_func() << endl;

    // If get_base() is redefined in derived w/o virtual, then 
    // inherited or base class get_base() is executed
    cout << b1 -> get_base() << endl;

}