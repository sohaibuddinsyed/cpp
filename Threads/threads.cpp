#include <iostream>
#include <thread>
#include <atomic>
#include <mutex>
#include <condition_variable>
#include <shared_mutex>
#include <vector>
#include <functional>

using namespace std;

void func(const string &s) {
    cout << s << ": " << endl;
    for(int i = 0; i < 10000000000; i++);
}

bool JOIN = 0;

int main() {

    function<void(string)> f = [](const string &s) {
        cout << s << ": " << endl;
        for(int i = 0; i < 10000000000; i++);
    };

    // f is an rval reference? or casted to one?
    thread th1(f, "Th1");
    thread th2(func, "Th2");
    thread th3(func, "Th3");
    th2.join();
    th1.join(); 
    th3.join(); 

    // function<void(vector<int>)> f = [](vector<int> a) {
    //     for(int i = 0; i < a.size(); i++)
    //         cout << a[i] << " " ;
    // };
    // vector<int> v = {1, 2, 3};

    // // takes lval refs for param
    // thread th2(f, v);
    // th2.join();

    // thread zombie_thread(func, 1);
    // zombie_thread.detach();
    // this_thread::sleep_for(chrono::seconds(9));
}