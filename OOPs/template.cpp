#include <iostream>
using namespace std;

// Declaration
template<class T, int N>
class MyChar;

template<typename T, int N>
void print_any(MyChar<T,N> C) {
    C.print_ch();
}

template<class T, int N>
class MyChar {
    T ch;
    int someInt;
public:
    MyChar(T ch_p) : ch(ch_p), someInt(N) {}
    void print_ch() {
        cout << ch << " " << someInt << endl;
    }

    friend ostream& operator<<(ostream& os, const MyChar<T, N> &c) {
        os << c.ch;
        return os;
    }

    MyChar operator+ (const MyChar &aa) const {
        MyChar newObj(this->ch + aa.ch);
        return newObj;
    }
};

// Template specialization for char
template<int N>
class MyChar <char, N> {
    char ch;
    int someInt;
public:
    MyChar(char ch_p) : ch(ch_p), someInt(N){}
    void print_ch() {
        cout << ch << " " << someInt << endl;
    }
    friend ostream& operator<<(ostream& os, const MyChar<char, N> &c) {
        os << c.ch;
        return os;  
    }
};


int main() {
    MyChar<int, 5> a(10), aa(100);
    MyChar<char, 10> b('a');

    a.print_ch();
    b.print_ch();
    
    print_any(b);

    MyChar<int, 5> aaa = a + aa;
    cout << aaa << endl;

    return 0;
}
