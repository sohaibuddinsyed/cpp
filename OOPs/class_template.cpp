#include <iostream>
using namespace std;

template<typename T>
void print_any(T ch) {
    cout << ch << endl;
}

template<class T>
class MyChar {
    T ch;
public:
    MyChar(T ch_p) : ch(ch_p) {}
    void print_ch() {
        cout << ch << endl;
    }

    friend ostream& operator<<(ostream& os, MyChar<T> &c) {
        os << c.ch;
        return os;
    }

    MyChar<int> operator+ (MyChar<int> &aa) {
        MyChar<int> newObj(0);
        newObj.ch = this -> ch + aa.ch;
        return newObj;
    }
    // friend MyChar<int> operator+ (MyChar<int> &a, MyChar<int> &aa) {
    //     a.ch += aa.ch;
    //     return a;
    // }
};

// Template specialization for char
template<>
class MyChar <char> {
    char ch;
public:
    MyChar(char ch_p) : ch(ch_p) {}
    void print_ch() {
        cout << ch << endl;
    }
    friend ostream& operator<<(ostream& os, MyChar &c) {
        os << c.ch;
        return os;  
    }
};


int main() {
    MyChar<int> a(10), aa(100);
    MyChar<char> b('a');

    a.print_ch();
    b.print_ch();
    
    print_any(b);

    MyChar<int> aaa = a + aa;
    cout << aaa << endl;
    cout << a << endl;

    return 0;
}