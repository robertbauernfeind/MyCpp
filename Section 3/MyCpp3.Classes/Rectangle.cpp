//
// Created by r.bauernfeind on 25.03.2025.
//

#include "Rectangle.h"
#include <iostream>

using namespace std;

int Rectangle::objectsCount = 0;

Rectangle::Rectangle(int width, int height) {
    objectsCount++;

    //:width{width}, height{height}
    cout << "Constructing a Rectangle" << endl;
    setHeight(height);
    setWidth(width);
}

// constructor delegation
Rectangle::Rectangle(int width, int height, const string &color): Rectangle(width, height) {
    cout << "Constructing a Rectangle with color" << endl;
    this->color = color;
}

Rectangle::Rectangle(const Rectangle &source) {
    cout << "Rectangle copied" << endl;
    this->width = source.width;
    this->height = source.height;
    this->color = source.color;
}

Rectangle::~Rectangle() {
    cout << "Destructing a Rectangle" << endl;
}

int Rectangle::getHeight() const {
    return height;
}

void Rectangle::setHeight(int height) {
    if (height < 0) {
        throw invalid_argument("height cannot be negative");
    }

    this->height = height;
}

int Rectangle::getWidth() const {
    return width;
}

void Rectangle::setWidth(int width) {
    if (width < 0) {
        throw invalid_argument("width cannot be negative");
    }

    // (*this).width = width;
    // shortcut:
    this->width = width;
}

void Rectangle::draw() const {
    cout << "Drawing a rectangle" << endl;
    cout << "Dimensions: " << width << ", " << height << endl;
}

int Rectangle::getArea() const {
    return width * height;
}

int Rectangle::getObjectsCount() {
    return objectsCount;
}
