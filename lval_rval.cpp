#include <iostream>
using namespace std;

int get_rvalue() {
    return 10;
}

int& get_lvalue_ref() {
    static int s = 10;
    return s;
}

// func that takes both lvalue and rvalue references
void const_func(const int &p) {
    cout << "const lval ref: "  << p << endl;
}

// func that takes only lvalue references
void func_lval(int &p) {
    cout << "Lvalue ref: " << p << endl;
}

// func accepts rvalue references or temporaries
void func_rval(int &&p) {
    cout << "Rvalue ref: " << p << endl;
}

int main() {
    // a is an lvalue
    int a = get_rvalue();
    // Can assign rvalue to an lvalue or an lvalue ref
    get_lvalue_ref() = 100;
    cout << "Static variable s is now: " << get_lvalue_ref() << endl;

    func_lval(get_lvalue_ref());
    func_lval(a);

    // invalid: cannot pass rvalues to an lvalue reference
    // func(10);
    // can pass rvalues to const lvalue ref. Workaround to pass both l/r values to funs
    const_func(10);
    func_rval(10);

    return 0;
}