#include <iostream>
using namespace std;

// mutable in 'const.cpp'

int GLOBAL_VAR;
extern void print();

void init() {
    // block scoped and program lifetime
    static int a = 10;
    a += 1;
    cout << "static: " << a << endl;

    // block scoped and block lifetime
    // The register keyword was deprecated in the 2011 C++ standard, 
    // as its effect was already implicit in the language.
    register int count = 1;
    count++;
    cout << "register: " << count << endl;
}

int main() {
    init();
    init();
    init();

    // global scoped variable initialized here and used as extern in 'extern_storage_class.cpp'
    // compile both files together so they can be linked
    GLOBAL_VAR = 10;
    cout << "Extern variable: ";
    print();
}