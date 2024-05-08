#include <iostream>
#include <memory>
using namespace std;

int main() {
    // Requires explicit ctor: (explicit) no implicit conversion
    unique_ptr<int[]> arr(new int[10]);
    // Can also do  
    unique_ptr<int[]> arr2 = make_unique<int[]>(10);
    for(int i = 0; i < 10; i++) {
        arr[i] = i * 2;
        cout << arr[i] << " ";
    }
    cout << endl;

    for(int i = 0; i < 10; i++) {
        arr2[i] = i;
        cout << arr2[i] << " ";
    }
    cout << endl;

    weak_ptr<int> weak_ptr;
    {
        // shared pointer maintains a ref count, deletes when 0
        shared_ptr<int> ptr = make_shared<int>(42);
        shared_ptr<int> ptr2 = ptr;
        cout << ptr2.use_count() << " " << *ptr2 << endl;

        weak_ptr = ptr;
        // Weak pointer does not increase the ref count
        cout << ptr2.use_count() << endl;

        // weak ptr observes shared ptr
        if(weak_ptr.lock())
            cout << "Shared is alive!" << endl;
    }
    if(!weak_ptr.lock())
        cout << "Shared is dead!" << endl;

    return 0;
}