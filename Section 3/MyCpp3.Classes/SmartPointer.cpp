//
// Created by r.bauernfeind on 25.03.2025.
//

#include "SmartPointer.h"
#include <iostream>

using namespace std;
SmartPointer::SmartPointer(int *ptr) {
    cout << "Creating a smart pointer" << endl;
    this->ptr = ptr;
}

SmartPointer::~SmartPointer() {
    cout << "Deleting the pointer" << endl;
    delete ptr;
    ptr = nullptr;
}
