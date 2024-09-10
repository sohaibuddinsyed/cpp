#include <iostream>
using namespace std;

const * func() {
    return "Hello";
}

int main() {
    cout << func();
    return 0;
}