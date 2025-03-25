//
// Created by r.bauernfeind on 25.03.2025.
//

#ifndef RECTANGLE_H
#define RECTANGLE_H


// The header file is basically a blueprint for the class.
// In other words, like in C# this would be an interface.

class Rectangle {
    // Access modifiers:
    // - private
    // - protected
    // - public

private:
    int width;
    int height;

public:
    int getHeight() const;

    void setHeight(int height);

    // Getter (accessor
    int getWidth() const;

    // Setter (mutator)
    void setWidth(int width);

    void draw();

    int getArea();
};


#endif //RECTANGLE_H
