#include <iostream>
#include <limits>
#include <vector>

using namespace std;

// ENUMS
// old way
// enum Action {
// strongly typed
enum class Action {
    List = 1,
    Add = 2,
    Update = 3
};

// PascalCase
struct Date {
    short year = 1900;
    short month = 1;
    short day = 1;
};

struct Movie {
    string title;
    Date date;

    // Method
    bool equals(const Movie &movie) const {
        return (title == movie.title &&
                date.year == movie.date.year &&
                date.month == movie.date.month &&
                date.day == movie.date.day);
    }

    // operator overloading option 1
    // bool operator == (const Movie &movie) const{
    //     return (title == movie.title &&
    //             date.year == movie.date.year &&
    //             date.month == movie.date.month &&
    //             date.day == movie.date.day);
    // }
};

struct Point {
    int x;
    int y;

    bool operator ==(const Point &other) const {
        return x == other.x && y == other.y;
    }
};

// operator overloading option 2
bool operator ==(const Movie &m1, const Movie &m2) {
    return (m1.title == m2.title &&
            m1.date.year == m2.date.year &&
            m1.date.month == m2.date.month &&
            m1.date.day == m2.date.day);
}

ostream &operator <<(ostream &os, const Point &p1) {
    return os << "(x: " << p1.x << ", y: " << p1.y << ")";
}

ostream &operator <<(ostream &os, const Movie &movie) {
    os << "Title: " << movie.title << ", Release Year: " << movie.date.year;
    return os;
}

struct Customer {
    int id = 0;
    string name;
    string email;
};

Movie getMovie() {
    Movie movie = {"Terminator", {1984, 12, 1}};
    return movie;
}

void showMovie(const Movie* movie) {
    // Structure pointer operator
    // (*movie).title
    // `->` dereferences the variable and then accesses the member
    cout << movie->title << endl;
}

int main() {
    Movie movie = {"Terminator", {1984, 12, 1}};
    // movie.title = "Terminator";
    // movie.releaseYear = 1984;

    // C++: structured binding
    // python: unpacking
    // javascript: destructuring
    auto [title, releaseYear] = movie;


    cout << "Title: " << movie.title << endl;
    cout << "ReleaseYear: " << movie.date.year << endl;

    // Exercise
    // Customer struct
    // * ID
    // * Name
    // * Email
    //
    // Ask the user for input and store in customer struct

    // comment in if want to use

    // Customer customer;
    // cout << "Enter customer ID: ";
    // while (true) {
    //     cin >> customer.id;
    //     if (cin.fail()) {
    //         cout << "Invalid Input, try again" << endl;
    //         cin.clear();
    //         cin.ignore(numeric_limits<int>::max(), '\n');
    //     } else break;
    // }
    //
    // cin.ignore(numeric_limits<int>::max(), '\n');
    //
    // cout << "Enter customer name: ";
    // getline(cin, customer.name);
    //
    // cout << "Enter customer email: ";
    // getline(cin, customer.email);
    //
    // cout << "Customer ID: " << customer.id << endl;
    // cout << "Customer Name: " << customer.name << endl;
    // cout << "Customer Email: " << customer.email << endl;


    // Vectors
    vector<Movie> movies;
    Movie m{"Terminator 1", 1984};
    movies.push_back(movie);
    movies.push_back({"Terminator 2", 1991});;

    cout << movies[0].title << endl;

    for (const auto &mov: movies) {
        cout << mov.title << endl;
    }

    // Comparing
    Movie m1 = {"Terminator 1", {1984, 1, 1}};
    Movie m2 = {"Terminator 1", {1984, 1, 1}};

    if (m1.equals(m2)) {
        cout << "Equal" << endl;
    }

    // operator overloading
    // ==, !=, <, >, <=, >=
    if (m1 == m2) {
        cout << "Equal - operator overloading ==" << endl;
    }

    cout << m1 << endl;

    // Exercise
    // Point struct
    Point p1 = {10, 20};
    Point p2 = {10, 20};

    if (p1 == p2) {
        cout << "Points are equal" << endl;
    } else {
        cout << "Points are not equal" << endl;
    }

    cout << (p1==p2) << endl;
    cout << p1 << endl << p2 << endl;


    // Structures and Functions, Pointers to Structures
    auto movie1 = getMovie();
    showMovie(&movie1);
    cout << Action::List << endl;
    cout << Action::Add << endl;
    cout << Action::Update << endl;

    // Defining enumerations (enum)
    return 0;
}
