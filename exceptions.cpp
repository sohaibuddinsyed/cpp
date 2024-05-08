#include <iostream>
#include <exception>
using namespace std;


class myexception: public exception
{
    virtual const char* what() const throw() {
        return "My exception happened";
    }
} myex;

void myFunction() noexcept {
    // Function body
}

int main() {
    try {
        int a = 10;
        // cout << a / 0;
        myFunction();
        throw myex;
    }
    // We have placed a handler that catches exception objects by reference 
    // (notice the ampersand & after the type), therefore this catches also classes 
    // derived from exception, like our myex object of type myexception.
    catch (exception& e) {
        if (noexcept(myFunction())) {
            cout << "Standard exception: " << e.what() << endl;
        } else {
            cout << "Standard exception can be from myFunction: " << e.what() << endl;
        }
    }
}