#include <iostream>
#include "Rectangle.h"
#include "TextBox.h"
#include <mem.h>
#include <memory>

#include "SmartPointer.h"

using namespace std;

void showRectangle(Rectangle &rectangle) {
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
    Rectangle rectangle{10, 20};

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
    Rectangle rectangle2{10, 20, "red"};

    // Copy  constructor
    Rectangle rectangle3 = rectangle2;
    showRectangle(rectangle2);

    // Destructor
    Rectangle rectangle4{20, 40};

    // Static members
    cout << Rectangle::getObjectsCount() << endl;

    // Constant objects
    // Immutable
    const Rectangle rectangle5;
    rectangle5.getWidth();
    // methods like setWidth() or setHeight() cannot be called on a const object

    // Pointer to objects
    // old way
    auto *rect = new Rectangle(10, 20);
    rect->draw();
    delete rect;
    rect = nullptr;

    // new way using smart pointers
    auto rect2 = make_unique<Rectangle>(10, 20);
    rect2->draw();

    // not needed because of smart pointers
    // delete rect2;
    // rect2 = nullptr;

    // == Exercise 2 ==
    // Create a class which implements a smart pointer
    SmartPointer sptr{new int};

    // ===

    // Array of Objects
    // for this the default ctor is needed
    Rectangle rectangles[5];

    Rectangle rectangles2[] = {
        {10, 20, "red"},
        {20, 30},
        {}
    };



    return 0;
}
