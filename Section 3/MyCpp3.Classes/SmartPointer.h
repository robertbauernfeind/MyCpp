//
// Created by r.bauernfeind on 25.03.2025.
//

#ifndef SMARTPOINTER_H
#define SMARTPOINTER_H

using namespace std;

class SmartPointer {
private:
    int* ptr;

public:
    explicit SmartPointer(int* ptr);
    ~SmartPointer();
};



#endif //SMARTPOINTER_H
