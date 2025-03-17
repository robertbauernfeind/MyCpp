#include <iostream>

using namespace std;

void increasePrice(double &price) {
    price *= 2;
}

void increasePrice(double *price) {
    // this functions accepts a pointer
    // which has to be dereferenced first in order
    // to multiply by two
    *price *= 2;
}

void printNumbers(int numbers[]) {
    // the numbers[] is just a pointer, so the size cannot
    // be specified by the 'size(numbers)' function
    // size(numbers);
    numbers[0] = 0;
}

void swap(int *first, int *second) {
    // dereference first
    int temp = *first;
    // dereference first and set to dereferenced second
    *first = *second;
    // dereference first and set to temp
    *second = temp;
}

int main() {
    // a pointer is the reference to the memory address of a variable
    int x = 10;
    // print the address with a '&' symbol
    cout << "x = " << x << " adr = " << &x << endl;

    // a pointer should always be initialized,
    // if the value is not known, it should be set to a nullptr
    // int* ptr = nullptr;
    int *ptr = &x;

    // dereference the pointer to get the value by using the '*' symbol
    cout << "ptr = " << ptr << " *ptr = " << *ptr << endl;


    // == constant pointer ==
    const int n = 10;
    // compilation error, constant variable reference cannot be set to
    // non constant pointer
    // int* ptrn = &n;

    // constant pointer pointing to a constant integer
    const int *const ptrn = &n;

    // passing pointers to functions
    double price = 100;
    cout << "price = " << price << endl;
    // this function accepts the refernce to the price variable
    // pointer way: (old)
    increasePrice(&price);

    // reference way: recommended (new)
    // increasePrice(price);
    // both ways result in the same

    cout << "increased price = " << price << endl;

    // == Exercise ==
    // swap two variables:
    int first = 10, second = 20;

    cout << "first = " << first << " second = " << second << endl;
    swap(&first, &second);
    cout << "swap first = " << first << " second = " << second << endl;

    // == Relationship between arrays and pointers ==
    cout << endl << "Relation between arrays and pointers: " << endl;
    int numbers[] = {10, 20, 30, 40};

    // the numbers array is actually just a reference to the first element
    // *numbers will print the first value
    cout << numbers << ", " << *numbers << endl;


    printNumbers(numbers);
    cout << numbers[0] << endl;

    // == Pointer arithmetic ==
    int numbers2[] = {10, 20, 30, 40, 50};
    int *ptr2 = numbers2;
    // memory ref: 100
    ptr2++; // => will result in memory ref: 104
    // because sizeof(int) is 4, so one integer uses 4 bits in memory
    // ptr 100 + 1 => 101, would be in the middle of the integer, does not make sense
    // so it will jump to the next element in the array, second element
    // will output the second element
    cout << *ptr2 << endl;
    ptr2--;
    // this is acctually the same as writing this:
    cout << *(ptr2 + 1) << endl;
    // or more common
    cout << numbers2[1] << endl;
    // or
    cout << ptr2[1] << endl;

    // ptr--;

    // == Comparing pointers ==
    cout << endl << "Comparing pointers: " << endl;
    int n3[] = {10, 20, 30, 40, 50};
    int* ptr3 = &n3[size(n3) - 1];

    while (ptr3 >= n3) {
        cout << *ptr3-- << endl;
    }

    // == Dynamic memory allocation ==
    // limits to 10 elements, always allocates space
    // for 10 elements in memory (40 bits)
    // declared in "Stack" => variables in "Stack" will get
    // automatically cleaned up when they get out of scope
    // int numbers3[10];

    // new int[10] returns a pointer to a
    // 10 size array
    // declared in "Heap" (Free Store)
    // will not get cleaned up automatically
    // when unhandled this will end up in a memory leakage
    int* numbers3 = new int[10];

    // this would technically work fine
    // but is in normal case not recommended
    // because will result in the same as "int number;"
    // int* number = new int;

    // clean up of array numbers3
    delete[] numbers3;
    // delete number

    // reset pointers, good practice
    // number = nullptr;
    numbers3 = nullptr;
    return 0;
}
