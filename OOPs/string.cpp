#include <iostream>
#include <cstring>
#include <memory>
using namespace std;

void memcpy(char* dest, const char* src, int size) {
    for(int i = 0; i < size; i++) {
        dest[i] = src[i];
    }
}

class String {
    unique_ptr<char[]> ptr;
    int size;
public:
    String() : size(0) {}
    String(const char* p) : size(strlen(p)) {
        ptr = make_unique<char[]>(size + 1);
        memcpy(ptr.get(), p, size + 1);
    }

    // Copy ctor
    String(const String &s) : size(s.size) {
        ptr = make_unique<char[]>(size + 1);
        memcpy(ptr.get(), s.ptr.get(), size + 1);
    }

    // Copy assignment operator
    String& operator=(const String &s) {
        if (this != &s) {
            size = s.size;
            ptr = make_unique<char[]>(size + 1);
            memcpy(ptr.get(), s.ptr.get(), size + 1);
        }
        return *this;
    }

    // Move ctor
    String(String &&s) noexcept : ptr(std::move(s.ptr)), size(s.size) {
        s.size = 0;
    }

    // Move assignment operator
    String& operator=(String &&s) noexcept {
        if (this != &s) {
            ptr = move(s.ptr);
            size = s.size;
            s.size = 0;
        }
        return *this;
    }

    friend ostream& operator<<(ostream& os, const String &s);
};

ostream& operator<<(ostream& os, const String &s) {
    os << s.ptr.get();
    return os;
}

int main() {
    String s("APPLE");
    cout << s;
    return 0;
}
