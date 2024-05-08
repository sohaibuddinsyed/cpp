#include <iostream>
#include <functional>

int myFunc(int a) {
    return a + 1;
}

int main() {
    int base = 1;

    // C style function pointer
    int (*funcPtr)(int) = myFunc;
    std::cout << funcPtr(10) << std::endl;

    // Lambda
    std::function<int(int)> myLambda = [&](int a) {
        base++;
        return base + a;
    };
    
    std::cout << myLambda(10) << std::endl;
}