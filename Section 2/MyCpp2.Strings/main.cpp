#include <iostream>
#include <string.h>

// both included in <iostream>
// #include <string>
// #include <cstring>

using namespace std;

void cStrings();

int main() {
    cStrings();
    return 0;
}

void cStrings() {
    // C-Strings
    cout << " == C-Strings == " << endl;

    // C Strings are not recommended anymore because they bring
    // several problems like buffer overflow, null terminator, etc.
    // e.g.
    // strings are defined like this:
    // char name[5];
    // theoretically it is possible to set a string with more characters
    // than 5 (4 with null terminator) but this will cause a buffer overflow
    // this won't cause an error immediately, but it will cause problems
    // because a space in the memory that is not reserved for the variable is written
    // and can overwrite other variables or even the program itself

    // space for 4 characters + null terminator = \0
    // char name[5] = {'J', 'o', 'h', 'n', '\0'};

    // String literal, null terminator is added automatically
    char name[5] = "John";
    char lastname[] = "Doe";

    // Concatenate (combine)
    // lastname will be added to variable name
    // this could cause a buffer overflow because
    // the size of name is 5 and lastname is 4
    strcat(name, lastname);

    // Copy
    // lastname = name;
    strcpy(name, lastname);

    // Compare
    // comparing two pointers will always return false
    // if (name == lastname)
    if (strcmp(name, lastname) == 0) {
        cout << name << " is the same" << endl;
    } else {
        cout << name << " is not the same" << endl;
    }
    cout << name << endl;
}
