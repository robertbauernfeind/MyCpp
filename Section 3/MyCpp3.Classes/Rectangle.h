//
// Created by r.bauernfeind on 25.03.2025.
//

#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <iostream>
using namespace std;

// The header file is basically a blueprint for the class.
// In other words, like in C# this would be an interface.
class Rectangle {
    // Access modifiers:
    // - private
    // - protected
    // - public

private:
    int width = 0;
    int height = 0;
    string color;

public:
    Rectangle(int width, int height);

    Rectangle(int width, int height, const string &color);

    // Copy constructor
    Rectangle(const Rectangle &source);

    // prevent copy constructor, only reference can be passed
    // Rectangle(const Rectangle &source) = delete;

    Rectangle() = default;


    int getHeight() const;

    void setHeight(int height);

    int getWidth() const;

    void setWidth(int width);

    void draw();

    int getArea();
};


#endif //RECTANGLE_H
