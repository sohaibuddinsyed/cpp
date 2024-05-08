#include <iostream>
using namespace std;

class Singleton {
public:
    // Can return reference of a local variable since static
    static Singleton& get() {
        // Object created in static segment once and referred on subsequent calls
        static Singleton s;
        return s;
    }   
    void hello() {
        cout << "Hello singleton classes with static.\n";
    }
};
int main() {
    Singleton::get().hello();
}