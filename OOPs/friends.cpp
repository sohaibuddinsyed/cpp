#include <iostream>
using namespace std;

class Square;

class Rectangle {
    int width, height;
  public:
    int area (){
        return (width * height);
    }
    void convert (Square a);
    friend int area(Rectangle r);
};

class Square {
    // notice no access specifiers or obj declared
    friend class Rectangle;
private:
    int side;
public:
    Square (int a) : side(a) {}
};

void Rectangle::convert (Square a) {
    width = a.side;
    height = a.side;
}

int area(Rectangle s) {
    int area = s.width * s.height;
    return area;
}
  
int main () {
    Rectangle rect;
    Square sqr (4);

    // rect can access sqr private and protected members
    rect.convert(sqr);

    // area is a friend function
    cout << rect.area() << endl;
    return 0;
}