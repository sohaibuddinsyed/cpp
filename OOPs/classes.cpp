#include <iostream>
using namespace std;

class Square {
    int num_of_sides;
public:
    Square() : num_of_sides(0), side(0) {}
    Square (int num_of_sidesP, int sideP) {
        num_of_sides = num_of_sidesP;
        side = sideP;
    }
    // Automatically considered an inline member function by the compiler
    int area () {
        return side * side;
    }
    int perimeter();

private:    
    int side;
} optional_obj;

// normal (not-inline) class member function
int Square::perimeter() {
    return num_of_sides * side;
}

int main() {
    Square s(10, 5);
    cout << optional_obj.area();
    cout << s.perimeter();
}