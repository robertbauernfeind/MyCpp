#include <iostream>
#include <limits>
#include <fstream>
#include <iomanip>
#include <string>
#include <sstream>

using namespace std;

struct Movie {
    int id;
    string title;
    int year;
};

void readingFromStreams();

void writingToTextFiles();

void readingFromTextFiles();

void writingToBinaryFiles();

void readingFromBinaryFiles();

void workingWithFileStreams();

void convertingValuesToStrings();

void parsingStrings();

int main() {
    // readingFromStreams();

    cout << endl;

    writingToTextFiles();

    cout << endl;

    readingFromTextFiles();

    cout << endl;

    writingToBinaryFiles();

    cout << endl;

    readingFromBinaryFiles();

    cout << endl;

    // workingWithFileStreams();

    cout << endl;

    convertingValuesToStrings();

    cout << endl;

    parsingStrings();

    cout << endl;
    return 0;
}

void userInput(const string &msg, int &value) {
    while (true) {
        cout << msg;
        cin >> value;
        if (cin.fail()) {
            cout << "Enter a valid number!" << endl;
            // set the stream in a clear state
            cin.clear();
            // remove everything from the buffer
            cin.ignore(numeric_limits<int>::max(), '\n');
        } else break;
    }
}

void readingFromStreams() {
    // Reading from streams

    // Buffer: temporary storage
    // input: [10 20]
    cout << endl << " == Reading from streams == " << endl;

    int first;
    int second;

    userInput("First: ", first);

    cin.ignore(numeric_limits<int>::max(), '\n');

    userInput("Second: ", second);

    cout << "You entered " << first << " and " << second << endl;
}

void writingToTextFiles() {
    cout << endl << " == Writing to text files == " << endl;

    // ofstream: output file stream
    ofstream file;
    // if the file does not exist, it will be created
    // if the file exists, it will be overwritten
    file.open("data.csv");

    if (file.is_open()) {
        // file implements same stream interface
        // as cout, so it can be used in the same way
        // with streams
        // file << setw(20) << "Hello" << setw(20) << "World!" << endl;

        // CSV:
        file << "id,title,year\n"
                << "1,Terminator 1, 1984\n"
                << "1,Terminator 2, 1991\n";

        // release file
        file.close();

        cout << "File written successfully!" << endl;
    }
}

void readingFromTextFiles() {
    // Reading from text files
    cout << endl << " == Reading from text files == " << endl;
    // ifstream: input file stream
    ifstream file;
    file.open("data.csv");

    if (file.is_open()) {
        string str;

        // same problem as with cin
        // stream stops at delimiter like ' ', '\n'
        // file >> str;
        // use getline() instead

        // eof = end of line
        getline(file, str);

        while (!file.eof()) {
            // default delimiter is '\n'

            getline(file, str, ',');
            if (str.empty()) continue;
            Movie movie;
            movie.id = stoi(str);

            getline(file, str, ',');
            movie.title = str;

            getline(file, str);
            movie.year = stoi(str);

            cout << movie.title << endl;
        }

        file.close();
    }
}

void writingToBinaryFiles() {
    // Writing to binary files
    cout << endl << " == Writing to binary files == " << endl;
    int numbers[] = {1'000'000, 2'000'000, 3'000'000};

    // Text file
    // expected file size: 24 bytes
    // ofstream file("numbers.txt");
    // // file.open("numbers.txt");
    //
    // if (file.is_open()) {
    //     for (const int number : numbers) {
    //         file << number << endl;
    //     }
    //
    //     file.close();
    // }

    // expected file size: 12 bytes
    // 12 => 3 * 4 bytes, 3* 4 integers
    ofstream file("numbers.dat", ios::binary);
    if (file.is_open()) {
        file.write(reinterpret_cast<char *>(&numbers), sizeof(numbers));
        file.close();
    }
}

void readingFromBinaryFiles() {
    // Reading from binary files
    cout << endl << " == Reading from binary files == " << endl;

    int numbers[3];

    ifstream file("numbers.dat", ios::binary);
    if (file.is_open()) {
        int number;
        while (file.read(reinterpret_cast<char *>(&number), sizeof(number))) {
            cout << number << endl;
        }
        file.close();
    }
}

void workingWithFileStreams() {
    // Working with file streams
    cout << endl << " == Working with file streams == " << endl;

    // difference from `fstream` to `ifsteam` and `ofstream`
    // is, that it can be used for both, reading and writing
    // to the same file by specifying the mode
    fstream file;

    // app => append
    file.open("file.txt", ios::in | ios::out | ios::app);

    if (file.is_open()) {
        file.close();
    }
}

// Exercise: convert a double to a string
// string dtos(double number) {
//     ostringstream oss;
//     oss << fixed << setprecision(1) << number;
//     return oss.str();
// }

// overloading to_string()
string to_string(double number, int precision = 1) {
    ostringstream oss;
    oss << fixed << setprecision(precision) << number;
    return oss.str();
}

void convertingValuesToStrings() {
    // Converting values to strings
    cout << endl << " == Converting values to strings == " << endl;

    double number = 12.34;
    ostringstream stream;

    // fixed: fixed point notation
    // setprecision: number of decimal places
    // stream << fixed << setprecision(1) << number;

    // string str = to_string(number);
    // string str = stream.str();
    string str = to_string(number, 2);
    cout << str << endl;
}

void parsingStrings() {
    // Parsing Strings
    cout << endl << " == Parsing Strings == " << endl;

    string str = "10 20";
    stringstream stream(str);

    int first;
    stream >> first;

    int second;
    stream >> second;

    cout << first << endl;
    cout << second << endl;

    // Exersice: parse to a Movie struct
    // Terminator 1, 1984

    string movieStr = "Terminator 1, 1984";
    stringstream movieStream(movieStr);
    // while (!movieStream.eof()) {
    //     string token;
    //     getline(movieStream, token, ',');
    //     Movie movie;
    //     movie.title = token;
    //
    //     getline(movieStream, token);
    //     movie.year = stoi(token);
    //
    //     cout << movie.title << endl;
    // }

    Movie movie;
    getline(movieStream, movie.title, ',');
    movieStream >> movie.year;

    cout << movie.title << endl;
    cout << movie.year << endl;
}
