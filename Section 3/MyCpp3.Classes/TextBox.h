//
// Created by r.bauernfeind on 25.03.2025.
//

#ifndef TEXTBOX_H
#define TEXTBOX_H

#include <iostream>

using namespace std;

class TextBox {
private:
    string value;

public:
    string getValue();

    void setValue(const string& value);
};


#endif //TEXTBOX_H
