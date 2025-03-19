#include <iostream>
#include <cstring>

// included in <iostream>
// #include <string>

using namespace std;

void cStrings();

void cppStrings();

void modifyingStrings();

void searchingStrings();

int main() {
    cStrings();
    cppStrings();
    modifyingStrings();
    searchingStrings();
    return 0;
}

void cStrings() {
    // C-Strings
    cout << endl << " == C-Strings == " << endl;

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

void cppStrings() {
    // CppStrings
    cout << endl << " == CppStrings == " << endl;

    // internally a char[]
    string name = "John";
    name[0] = 'j';

    name += " Doe";

    // Copy strings
    string another = name;
    // Compare strings
    if (name == another) {
        cout << name << " is the same" << endl;
    }

    cout << name << " " << name.length() << endl;

    // Replaces indexing first element with 0
    // and last element with [name.length() - 1]
    cout << name.front() << " " << name.back() << endl;
}

void modifyingStrings() {
    // Modifying strings
    cout << endl << " == ModificationStrings == " << endl;

    string name = "John";

    // Append
    name.append("Doe");
    cout << name << endl;

    // Insert
    name.insert(0, "I am ");
    cout << name << endl;

    // Erase
    name.erase(0, 2);
    cout << name << endl;

    // Clear
    // set to "" string, empty string
    name.clear();
    cout << "emtpy string: " <<name << endl;
}

void searchingStrings() {
    // Searching strings
    cout << endl << " == SearchStrings == " << endl;

    string name = "John Doe";

    // will return max `size_t` if not found
    // equivalent to -1
    // `size_t` cannot store negative numbers, because it is basically
    // an unsigned long long
    // when assigning -1 to a `size_t` variable, it will be converted to
    // the maximum value of `size_t` because of underflow
    cout << name.find('a') << endl;

    if (name.find("Jo") == -1) {
        cout << "string not found" << endl;
    } else {
        cout << "string found" << endl;
    }


    // like last index of
    cout << "reverse find: " << name.rfind('o') << endl;

    cout << "first of: " << name.find_first_of('o') << endl;
    cout << "last of: " << name.find_last_of('o') << endl;
    cout << "first not of" << name.find_first_not_of('o') << endl;

    // Escape characters, raw strings
    // string str = "C:\\my folder\\\"Hello World\"";
    string str = R"("C:\my folder\"Hello World")";
}
