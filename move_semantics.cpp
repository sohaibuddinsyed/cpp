#include <iostream>
#include <cstring>
using namespace std;

class String {
    const char *str;
    unsigned int size;
public:
    String() = default;
    String(const char *p) {
        cout << "Constructor called. \n";
        size = strlen(p);
        str = new char[size];
        memcpy(const_cast<char *>(str), p, size);
    }
    String(const String& s) {
        cout << "Copy constructor called. \n";
        size = s.size;
        str = new char[size];
        memcpy(const_cast<char *>(str), s.str, size);
    }

    // rvalue refs are temporaries, overwrite the value in curr obj and make temporaries null
    String(String&& p) {
        cout << "Move constructor called. \n";
        size = p.size;
        str = p.str;

        p.str = nullptr;
        p.size = 0;
    }

    // We pass an lvalue reference casted as an rvalue reference using explicit cast or move()
    String& operator=(String&& p) {
        cout << "Move assignment called. \n";
        if(this != &p) {
            size = p.size;

            // To prevent a dangling pointer on current obj
            delete[] str;
            str = p.str;

            p.str = nullptr;
            p.size = 0;
        }
        return *this;
    }
    void print() {
        for(int i = 0 ; i < size; i++) {
            cout << str[i];
        }
        cout << endl;
    }

    ~String() {
        cout << "Destructor called. \n";
        delete[] str;
    }
};

class Entity {
    String s;
public:
    Entity() {};
    // Can make this const to pass both l and rvalue refs
    Entity(String &p): s(p) {}
    // Call a move ctor on String
    Entity(String &&p): s(move(p)) {
        cout << "Entity called move ctor\n";
    }
};

int main() {
    // We make an obj of String type "APPLE" and move in into s 
    // (instead of copying and keeping "APPLE" in s as well as in the String object memory location).
    String s("APPLE");
    // We make an obj of String type "BALL" and move in into newstr.
    String newStr("BALL");

    s.print();
    newStr.print();
    // We move newStr into s and make newStr null 
    // (nothing to delete left and no memory cost incurred by newstr)
    // We should make newStr as an rvalue ref to invoke move assignment
    s = (String &&) newStr; // s = move(newStr);
    s.print();
    newStr.print();

    cout << "\nEntity class:\n";

    // e1 will invoke move constructor on rvalue ref passed
    Entity e1(String("APPLE"));
}