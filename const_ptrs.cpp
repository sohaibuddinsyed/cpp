#include <iostream>
using namespace std;

int main() {
    const int IMP_CONST = 74;

    int *ptr1 = new int;
    ptr1 = (int*)(&IMP_CONST);
    *ptr1 = -29147;

    const int *ptr2 = new int;
    ptr2 = (int*)(&IMP_CONST);
    // invalid: cannot modify the pointing value
    // *ptr2 = -29147;

    int* const ptr3 = new int;
    // invalid: cannot modify/reassign the pointer
    // ptr3 = (int*)(&IMP_CONST);
    *ptr3 = -29147;

    const int* const ptr4 = new int;
    // invalid: cannot modify/reassign the pointer
    // ptr4 = (int*)(&IMP_CONST);
    // invalid: cannot modify the pointing value
    // *ptr4 = -29147;

    return 0;
}