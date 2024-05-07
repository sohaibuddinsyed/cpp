#include <iostream>
#include <thread>
#include <atomic>
#include <mutex>
#include <condition_variable>
#include <shared_mutex>

using namespace std;

void func(int a) {
    cout << a << endl;
}

bool JOIN = 0;

int main() {

    thread th1(func, 1);
    th1.join();

    // thread zombie_thread(func, 1);
    // zombie_thread.detach();
    // this_thread::sleep_for(chrono::seconds(9));
}