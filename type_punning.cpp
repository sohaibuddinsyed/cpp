#include <iostream>
using namespace std;

struct Entity {
public:
    int x, y;
};

struct Vector2 {
    int x, y;
    void print() {
        cout << x << " " << y << endl;
    }
};

// Anonymous unions to type punning
struct Vector4 {
    union 
    {
        // Both point to the same memory
        struct {
            int w, x, y ,z;
        };
        struct 
        {
            Vector2 a, b;
        };
        
    };
};


int main() {
    Entity e {3, 5};
    
    // Address can be casted into pointer types
    int x = *((int*)(&e));
    cout << x << endl;
    int y = *(reinterpret_cast<int*>(&e) + 1);
    cout << y << endl;

    Vector4 v4 = {1, 2, 3, 4};
    cout << v4.w << " " << v4.x << " " << v4.y << " " << v4.z << endl;
    cout << "Printing using v2" << endl;
    v4.a.print();
    v4.b.print();
    return 0;
}