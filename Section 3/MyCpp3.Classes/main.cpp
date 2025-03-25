#include <iostream>
#include "Rectangle.h"
#include "TextBox.h"

using namespace std;

void showRectangle(Rectangle& rectangle) {
}

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

    // Rectangle rectangle(10,20);
    Rectangle rectangle{10,20};

    // rectangle.setWidth(10);
    // rectangle.setHeight(20);

    cout << rectangle.getArea() << endl;


    // == Exercise 1 ==
    // Create a TextBox class with a string value field.

    TextBox box;
    box.setValue("Hello, World!");
    cout << box.getValue() << endl;

    // ===

    // Constructor delegation
    Rectangle rectangle2{10,20, "red"};

    // Copy  constructor
    Rectangle rectangle3 = rectangle2;
    showRectangle(rectangle2);
    return 0;
}