#include <iostream>
using namespace std;

enum Color {
    apple = 1,
    banana = 2,
    mango = 4,
    // Takes value 5
    cherry
};

enum class Fruit: int {
    APPLE = 1,
    banana,
    mango = 4,
    // Takes value 5
    cherry
} f;

int main() {
    // Optional namespace and implicitly convertible to an integer type
    cout << apple << " " << Color::banana << " " << cherry << endl;

    // Strictly namespace bound and can be explicitly converted to integral types
    Fruit f = Fruit::APPLE;
    int value = static_cast<int>(f);
    cout << value << endl;
    return 0;
}