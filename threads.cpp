#include <iostream>
#include <thread>
#include <atomic>
#include <mutex>
#include <condition_variable>
#include <shared_mutex>
#include <vector>
#include <functional>

using namespace std;

void func(int a) {
    cout << a << endl;
}

void f(vector<int> a) {
        for(int i = 0; i < a.size(); i++)
            cout << a[i] << " " ;
    };

bool JOIN = 0;

int main() {

    thread th1(func, 1);
    th1.join(); 

    function<void(vector<int>)> f = [](vector<int> a) {
        for(int i = 0; i < a.size(); i++)
            cout << a[i] << " " ;
    };
    vector<int> v = {1, 2, 3};
    // takes lval refs for param
    thread th2(f, v);
    th2.join();

    // thread zombie_thread(func, 1);
    // zombie_thread.detach();
    // this_thread::sleep_for(chrono::seconds(9));
}