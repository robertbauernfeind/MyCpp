//
// Created by r.bauernfeind on 25.03.2025.
//

#include "TextBox.h"

string TextBox::getValue() {
    return value;
}

void TextBox::setValue(const string& value) {
    this->value = value;
}
