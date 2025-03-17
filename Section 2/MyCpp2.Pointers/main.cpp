#include <iostream>

using namespace std;

int main() {
    // a pointer is the reference to the memory address of a variable
    int x = 10;
    // print the address with a '&' symbol
    cout << "x = " << x << " adr = " << &x<< endl;

    // a pointer should always be initialized,
    // if the value is not known, it should be set to a nullptr
    // int* ptr = nullptr;
    int* ptr = &x;

    // dereference the pointer to get the value by using the '*' symbol
    cout << "ptr = " << ptr << " *ptr = " << *ptr << endl;
    return 0;
}