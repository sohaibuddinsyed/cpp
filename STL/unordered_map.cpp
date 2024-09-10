#include <iostream>
#include <unordered_map>
using namespace std;

// Takes both lval and rvl references
void send_map(const unordered_map<int, int> &m1) {

}

int main() {
    unordered_map<int, int> m1;
    send_map(m1);
    send_map({{1,2}, {3,4}});
    return 0;
}