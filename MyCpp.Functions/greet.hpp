// Content: Declaration of the greet function
//ifndef GREET checks on build time if the function is already declared
// if not, it declares the function
// the function is defined in greet.cpp
#ifndef GREET
#define GREET

#include <string>
using namespace std;

void greet(string& name);

#endif