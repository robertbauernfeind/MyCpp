#include <iostream>
#include "Rectangle.h"
#include "TextBox.h"

using namespace std;

int main() {
    // Structures vs Classes
    // Structs:
    // - Data
    // - Members are public by default
    // Classes:
    // - Data + Behaviour
    // - Encapsulation
    //  - Combining the data and functions that
    //    operate on the data into a single unit
    // - Inheritance
    // - Polymorphism
    // - Abstraction

    std::cout << " ==== Classes ====" << std::endl;

    Rectangle rectangle;
    rectangle.setWidth(10);
    rectangle.setHeight(20);

    cout << rectangle.getArea() << endl;


    // == Exercise 1 ==
    // Create a TextBox class with a string value field.

    TextBox box;
    box.setValue("Hello, World!");
    cout << box.getValue() << endl;
    return 0;
}