#include <iostream>
using namespace std;

class Base { 
public:
    virtual void dummy() {
        cout << "Base dummy\n";
    } 
};
class Derived: public Base { 
    int a; 
public:
    int b;
    void dummy() {
        cout << "Derived dummy\n";
    }
    void only_derived_dummy() {
        cout << "Only Derived dummy\n";
        cout << a << endl;
    }
    Derived(): b(100) {}
    Derived(int b): b(b) {}
};

int main() {
    // Implicit upcast
    Base *b1 = new Derived;
    // Downcast: polymorphic classes (atleast one virtual func) and pointed obj is a valid complete object of the Derived type
    Derived *d1 = dynamic_cast<Derived*>(b1);

    Derived *d2 = new Derived;
    // Upcase: polymorphic classes and pointed obj is a valid complete object of the Base type
    Base *b2 = dynamic_cast<Base*>(d2);

    // Static cast: No runtime type checking and allows downcasts
    // Derived ptr is pointing to base object!!!
    Base *b3 = new Base;
    Derived *d3 = static_cast<Derived*>(b3);
    // could lead to runtime errors
    d3 -> only_derived_dummy();
    return 0;   
}