#include <iostream>
using namespace std;

const int add(int a, int b) {
    
    return a;
}

int main() {
    int a = 10, b = 5;
    const int c = add(a, b);
    return 0;
}