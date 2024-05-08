#include <iostream>
#include <cassert>
using namespace std;

int main() {
    int x = 10;
    // Assertions in C++ are mechanisms used to check assumptions about the state of a program during runtime.
    assert(x == 10);
    // Exits with the assertion failing
    assert(x == 11);
    return 0;
}